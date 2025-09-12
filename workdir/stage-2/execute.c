#include "execute.h"

static uint32_t used = 0;

int getReg() {
    for(int i=0;i < 20; i++) {
        if(!(used & (1u << i ))) {
            used |= (1u << i) ;
            return i;
        }
    }
    return -1 ;
}

int freeReg(int reg) {
    if(reg >= 0 && reg < 20 && (used & (1u << reg))) {
        used &= ~(1u << reg) ;
        return 0;
    }
    return -1 ;
}

void finalOutput(struct tnode * root, FILE * op) {
    fprintf(op, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(op, "ADD SP, 26\n");
    int r = codeGen(root, op);
    if(r != -1) {
        freeReg(r);
    }
    exitProg(op);
}

int codeGen(struct tnode * root, FILE * op) {
    if(!root) return -1;

    if(root->nodetype == LEAF_NODE) {
        int reg = getReg();

        if(root->type == INT_TYPE) {
            fprintf(op, "MOV R%d, %d\n",reg, root->val);
        }

        else if(root->type == ID_TYPE) {
            int offset = root->varname[0] - 'a' ;

            fprintf(op, "MOV R%d, 4096\n",reg);
            fprintf(op, "ADD R%d, %d\n",reg, offset);
            fprintf(op, "MOV R%d, [R%d]\n",reg,reg);
        }
        return reg ;
    }

    switch(root->nodetype) {
        case ADD_NODE   :
        case MINUS_NODE :
        case MUL_NODE   :
        case DIV_NODE   :{
            return exprEvaluate(op,root);
        }

        case READ_NODE  : {
            readFromTerminal(op,root->left->varname[0]);
            return -1;
        }

        case WRITE_NODE : {
            int reg = exprEvaluate(op, root->left);
            writeToTerminal(op,reg);
            freeReg(reg);

            return -1;
        }

        case ASSIGN_NODE : {
            int reg = exprEvaluate(op, root->right);
            int addr = getReg();
            int offset = root->left->varname[0] - 'a' ;

            fprintf(op, "MOV R%d, 4096\n",addr);
            fprintf(op, "ADD R%d, %d\n",addr, offset);
            fprintf(op, "MOV [R%d], R%d\n",addr,reg);

            freeReg(addr);
            freeReg(reg);

            return -1;
        }

        case CONNECT_NODE : {
            codeGen(root->left,op);
            codeGen(root->right,op);
            return -1;
        }

        default:
            return -1;
    }
}

int exprEvaluate(FILE * op, struct tnode * root) {
    if(!root) {
        return -1 ;
    }

    if(root->nodetype == LEAF_NODE) {
        int reg = getReg();

        if(reg == -1) {
            printf("Out of registers\n");
            exit(1);
        }

        if(root->type == INT_TYPE) {
            fprintf(op, "MOV R%d, %d\n",reg, root->val);
        }

        else if(root->type == ID_TYPE) {
            int offset = root->varname[0] - 'a' ;

            fprintf(op, "MOV R%d, 4096\n",reg);
            fprintf(op, "ADD R%d, %d\n",reg, offset);
            fprintf(op, "MOV R%d, [R%d]\n",reg,reg);
        }
        return reg ;
    }

    int left = codeGen(root->left,op);
    int right = codeGen(root->right,op);
    
    switch(root->nodetype) {
        case ADD_NODE :
            fprintf(op,"ADD R%d, R%d\n",left,right);
            break;
        
        case MINUS_NODE :
            fprintf(op,"SUB R%d, R%d\n",left,right);
            break;
        
        case MUL_NODE :
            fprintf(op,"MUL R%d, R%d\n",left,right);
            break;
        
        case DIV_NODE :
            fprintf(op,"DIV R%d, R%d\n",left,right);
            break;
    }
    freeReg(right);
    return left ;
}


void readFromTerminal(FILE *op, char ch) {
    int offset = ch - 'a' ;
    int reg1 = getReg();

    fprintf(op, "MOV R%d, \"READ\"\n",reg1);
    fprintf(op, "PUSH R%d\n",reg1);
    fprintf(op, "MOV R%d, -1\n",reg1);
    fprintf(op, "PUSH R%d\n", reg1);
    fprintf(op, "MOV R%d, 4096\n",reg1);
    fprintf(op, "ADD R%d, %d\n",reg1,offset);
    fprintf(op, "PUSH R%d\n",reg1);
    fprintf(op, "PUSH R%d\n",reg1);
    fprintf(op, "PUSH R%d\n",reg1);

    fprintf(op, "CALL 0\n");

    int reg2 = getReg();
    
    fprintf(op, "POP R%d\n",reg2);
    fprintf(op, "POP R%d\n",reg1);
    fprintf(op, "POP R%d\n",reg1);
    fprintf(op, "POP R%d\n",reg1);
    fprintf(op, "POP R%d\n",reg1);

    freeReg(reg2);
    freeReg(reg1);
}

void writeToTerminal(FILE *op , int reg) {
    int reg1 = getReg();
    if(reg1 == -1) {
        printf("Out of Registers\n");
        exit(1);
    }

    fprintf(op, "MOV R%d, \"WRITE\"\n",reg1);
    fprintf(op, "PUSH R%d\n",reg1);
    fprintf(op, "MOV R%d, -2\n",reg1);
    fprintf(op, "PUSH R%d\n", reg1);
    fprintf(op, "PUSH R%d\n",reg);          //Data to be written
    fprintf(op, "PUSH R%d\n",reg1);
    fprintf(op, "PUSH R%d\n",reg1);

    fprintf(op, "CALL 0\n");

    int reg2 = getReg();
    
    fprintf(op, "POP R%d\n",reg2);
    fprintf(op, "POP R%d\n",reg1);
    fprintf(op, "POP R%d\n",reg1);
    fprintf(op, "POP R%d\n",reg1);
    fprintf(op, "POP R%d\n",reg1);

    freeReg(reg2);
    freeReg(reg1);
}

void exitProg(FILE * op) {
    int r = getReg();

    fprintf(op, "MOV R%d, \"Exit\"\n",r);
    fprintf(op, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n",r,r,r,r,r);
    fprintf(op, "CALL 0\n");

    freeReg(r);
}

static int nums[26] = {0};

int evaluate(struct tnode * root) {
    if(!root) {
        return -1 ;
    }

    if(root->nodetype == LEAF_NODE) {
        if(root->type == INT_TYPE) {
            return root->val ;
        } else if(root->type == ID_TYPE) {
            return nums[root->varname[0] - 'a'] ;
        }
        return -1;
    }

    switch(root->nodetype) {
        case ADD_NODE :
            return evaluate(root->left) + evaluate(root->right);

        case MINUS_NODE :
            return evaluate(root->left) - evaluate(root->right);

        case MUL_NODE :
            return evaluate(root->left) * evaluate(root->right);

        case DIV_NODE :
            return evaluate(root->left) / evaluate(root->right);

        case ASSIGN_NODE :{
            nums[root->left->varname[0] - 'a'] = evaluate(root->right);
            return -1;
        }

        case CONNECT_NODE : {
            evaluate(root->left);
            evaluate(root->right);
            return -1 ;
        }

        case WRITE_NODE : {
            printf("%d\n",evaluate(root->left));
            return -1 ;
        }

        case READ_NODE : {
            int index = root->left->varname[0]- 'a' ;
            scanf("%d",&nums[index]);
            return -1;
        }

        default :
            return -1 ;
    }
}

void evaluator(struct tnode * root) {
    evaluate(root);

    for(int i=0;i<26;i++) {
        if(nums[i] != 0) {
            printf("%c - %d\n", 'a' + i, nums[i]);
        }
    }
}

// void inorder(struct tnode * root)  {
//     if(root) {
//         inorder(root->left);
//         printf("%d ",root->nodetype);
//         inorder(root->right);
//     }
// }