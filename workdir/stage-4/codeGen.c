#include "codeGen.h"
#include "exptree.h"
#include "symbolTable.h"

#define STACK_SIZE 100

int continueStack[STACK_SIZE] ;
int breakStack[STACK_SIZE];

int stackTop = -1 ;
int maxLabel  = -1;
int maxReg = -1;

int getLabel() {
    return ++maxLabel ;
}

int getReg() {
    if(maxReg < 16) {
       return ++maxReg ;
    } else {
        printf("Out of registers\n");
    }
    return -1 ;
} 

void freeReg() {
    if(maxReg >= 0) {
        maxReg-- ;
    } else {
        printf("Error freeing registers\n");
        exit(1);
    }
}

int getBreakLabel() {
    return breakStack[stackTop];
}

int getContinueLabel() {
    return continueStack[stackTop];
}

void pushLabel(int breakLabel, int continueLabel) {
    if(stackTop + 1 >= STACK_SIZE) {
        printf("Stack Size Exceeded\n");
        exit(1);
    }
    stackTop++ ;

    breakStack[stackTop] = breakLabel ;
    continueStack[stackTop] = continueLabel ;
}

void popLabel() {
    if(stackTop < 0) {
        printf("Popping from Empty Stack\n");
        exit(1) ;
    }
    stackTop-- ;
}

int getAddress(struct tnode * root,FILE * op) {
    if (!root) { 
        printf("getAddress called with NULL\n"); exit(1); 
    }

    switch(root->nodetype) {
        case ARR_NODE : { 
            int baseReg = getReg();
            int baseAddress = root->Gentry->binding ;
            int offsetReg = codeGen(root->left,op);

            fprintf(op, "MOV R%d, %d\n",baseReg,baseAddress);
            fprintf(op, "ADD R%d, R%d\n",baseReg,offsetReg );
            freeReg();
            return baseReg ;
        }

        case ID_NODE : {
            int r1 = getReg();
            int address = root->Gentry->binding ;

            fprintf(op, "MOV R%d, %d\n",r1,address);
            return r1 ;
        }
    }
}


void auxFunctions(FILE * op, int codePrint, int reg1, int reg2) {
    switch(codePrint) {
        case  ENTRY_CODE : {
            fprintf(op, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
            fprintf(op, "MOV SP, 4196\n");
            break;
        }

        case  EXIT_CODE : {
            fprintf(op, "MOV R0, \"Exit\"\n");
            fprintf(op, "PUSH R0\n");
            fprintf(op, "PUSH R0\n");
            fprintf(op, "PUSH R0\n");
            fprintf(op, "PUSH R0\n");
            fprintf(op, "PUSH R0\n");
            fprintf(op, "CALL 0\n");
            break;
        }

        case  READ_CODE : {
            fprintf(op, "MOV R%d, \"Read\"\n",reg1);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "MOV R%d, -1\n",reg1);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "MOV R%d, R%d\n",reg1, reg2);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "CALL 0\n");
            fprintf(op, "POP R%d\n",reg1);
            fprintf(op, "POP R%d\n",reg1);
            fprintf(op, "POP R%d\n",reg1);
            fprintf(op, "POP R%d\n",reg1);
            fprintf(op, "POP R%d\n",reg1);
            break;
        }

        case  WRITE_CODE : {
            fprintf(op, "MOV R%d, \"Write\"\n",reg1);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "MOV R%d, -2\n",reg1);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "MOV R%d, R%d\n",reg1, reg2);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "PUSH R%d\n",reg1);
            fprintf(op, "CALL 0\n");
            fprintf(op, "POP R%d\n",reg1);
            fprintf(op, "POP R%d\n",reg1);
            fprintf(op, "POP R%d\n",reg1);
            fprintf(op, "POP R%d\n",reg1);
            fprintf(op, "POP R%d\n",reg1);
            break;
        }
    }
}


int codeGen(struct tnode * root, FILE * op) {
    int r1, r2, label1, label2 ;

    switch(root->nodetype) {
        case NUM_NODE :{
            r1 = getReg();
            fprintf(op, "MOV R%d, %d\n",r1,root->val);
            return r1 ;
        }
        case ID_NODE :{
            r1 = getReg();
            
            int idAddress = root->Gentry->binding ;
            fprintf(op, "MOV R%d, [%d]\n",r1,idAddress);
            return r1 ;
        }
        case ARR_NODE : {
            int addrReg = getAddress(root,op);
            int valReg = getReg();

            fprintf(op,"MOV R%d, [R%d]\n",valReg,addrReg);
            freeReg();
            return valReg ;
        }
        case STR_NODE :{
            r1 = getReg();
            fprintf(op, "MOV R%d, \"%s\"\n",r1,root->varname);
            return r1 ;
        }
        case READ_NODE :{
            int r1 = getReg() ;
            int effectiveAddress = getAddress(root->left,op);

            auxFunctions(op,READ_CODE,r1,effectiveAddress);

            freeReg();
            return -1;
        }
        case WRITE_NODE :{
            r1 = getReg();
            r2 = codeGen(root->left,op);

            auxFunctions(op,WRITE_CODE,r1,r2);
            freeReg();
            freeReg();
            return -1;
        }
        case IF_NODE :{
            label1 = getLabel() ;

            r1 = codeGen(root->left,op);
            fprintf(op, "JZ R%d, L%d\n",r1,label1);
            freeReg();

            if(root->right->nodetype == ELSE_NODE) {
                r1 = codeGen(root->right->left,op) ;
                label2 = getLabel() ;
                fprintf(op, "JMP L%d\n",label2);

                fprintf(op, "L%d:\n",label1);
                r1 = codeGen(root->right->right,op);
                freeReg();
            } else {
                r1 = codeGen(root->right,op);
                freeReg();
                fprintf(op, "L%d:\n",label1);
            }
            return -1 ;
        }
        case WHILE_NODE :{
            label1 = getLabel() ;
            label2 = getLabel() ;

            pushLabel(label2,label1);

            fprintf(op, "L%d:\n",label1);
            r1 = codeGen(root->left,op);
            fprintf(op, "JZ R%d, L%d\n",r1,label2);
            freeReg();

            codeGen(root->right,op);
            fprintf(op, "JMP L%d\n",label1);
            fprintf(op, "L%d:\n",label2);

            popLabel();

            return -1;
        }
        case ASSIGN_NODE :{
            r2 = codeGen(root->right,op);
            int assignAddress = root->left->Gentry->binding ;
            fprintf(op, "MOV [%d], R%d\n",assignAddress,r2);
            freeReg();
            return -1;
        }
        case ADD_NODE :{
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "ADD R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case MINUS_NODE :{
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "SUB R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case MUL_NODE :{
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "MUL R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case DIV_NODE :{
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "DIV R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case GT_NODE :{
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "GT R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case GE_NODE :{
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "GE R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case LT_NODE :{
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "LT R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case EQ_NODE : {
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "EQ R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case NE_NODE : {
            r1 = codeGen(root->left,op);
            r2 = codeGen(root->right,op);
            fprintf(op, "NE R%d, R%d\n",r1,r2);
            freeReg();
            return r1 ;
        }
        case CONNECT_NODE : {
            codeGen(root->left,op);
            codeGen(root->right,op);
            return -1;
        }
        case CONTINUE_NODE :{
            fprintf(op, "JMP L%d\n",getContinueLabel());
            return -1;
        }
        case BREAK_NODE : {
            fprintf(op, "JMP L%d\n",getBreakLabel());
        }

    }

}

void inorder(struct tnode * root) {
    if(root ) {
        inorder(root->left);
        
        switch(root->nodetype) {
            case NUM_NODE : {
                printf("%d ",root->val);
                break;
            }
            case ID_NODE : {
                printf("%s ",root->varname);
                break;
            }
            case ARR_NODE : {
                printf("%s ",root->varname);
            }
            case READ_NODE : {
                printf("Read ");
                break;
            }
            case WRITE_NODE : {
                printf("Write ");
                break;
            }
            case ASSIGN_NODE : {
                printf("= ");
                break;
            }
            case ADD_NODE : {
                printf("+ ");
                break;
            }
            case MINUS_NODE : {
                printf("- ");
                break;
            }
            case MUL_NODE : {
                printf("* ");
                break;
            }
            case DIV_NODE : {
                printf("/ ");
                break;
            }
            case IF_NODE : {
                printf("if ");
                break;
            }
            case ELSE_NODE : {
                printf("else ");
            }
            case WHILE_NODE : {
                printf("while ");
                break;
            }
            case LT_NODE : {
                printf("< ");
                break;
            }
            case LE_NODE : {
                printf("<= ");
                break;
            }
            case GT_NODE : {
                printf("> ");
                break;
            }
            case GE_NODE : {
                printf(">= ");
                break;
            }
            case NE_NODE : {
                printf("!= ");
                break;
            }
            case EQ_NODE : {
                printf("== ");
                break;
            }
        }
        inorder(root->right);
    }
}
