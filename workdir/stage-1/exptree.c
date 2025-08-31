#include "exptree.h"

struct tnode * createLeafNode(int n) {
    struct tnode * temp = malloc(sizeof(struct tnode ));

    temp->val = n ;
    temp->op = NULL ;
    temp->left = temp->right = NULL ;

    return temp ;
}

struct tnode* createOperatorNode(char op, struct tnode * left, struct tnode * right) {
    struct tnode * temp = malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));

    *(temp->op) = op ; 
    temp->left = left;
    temp->right = right ;

    return temp ;
}

void prefix(struct tnode * root) {
    if(root) {
        if(!(root->op)) {
            printf("%d ", root->val);
        } else {
            printf("%c ",*(root->op));
        }

        prefix(root->left);
        prefix(root->right);
    }
}

void infix(struct tnode * root) {
    if(root) {
        infix(root->left);

        if(!(root->op)) {
            printf("%d ", root->val);
        } else {
            printf("%c ",*(root->op));
        }

        infix(root->right);
    }
}

void postfix(struct tnode * root) {
    if(root) {
        postfix(root->left);
        postfix(root->right);

        if(!(root->op)) {
            printf("%d ", root->val);
        } else {
            printf("%c ",*(root->op));
        }
    }
}

int evaluate(struct tnode * t) {
    if(t->op == NULL) {
        return t->val ;
    } else {
        switch(*(t->op)) {
            case '+' :  return evaluate(t->left) + evaluate(t->right) ;

            case '-' :  return evaluate(t->left) - evaluate(t->right) ;

            case '*' :  return evaluate(t->left) * evaluate(t->right) ;

            case '/' :  return evaluate(t->left) / evaluate(t->right) ;
        }
    }
    return 0;
}

static uint32_t used = 0;

void execGen(struct tnode* root, FILE* ptr){

    fprintf(ptr, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    int r = codeGen(root, ptr);
    printRes(r, ptr);

    freeReg(r);
    exitProg(ptr);
}

int getReg(){
    for(int i = 0; i<20; i++){
        if(!(used & (1u <<i))){
            used |= (1u <<i);
            return i;
        }
    }
    return -1;
}

int freeReg(int r){
    if(r>=0 && r<20 && (used & (1u <<r))){
        used &= ~(1u <<r);
        return 0;
    }
    return -1;
}

int codeGen(struct tnode * root, FILE *ptr) {
    if(!(root->op)) {
        int reg = getReg();
        if(reg == -1) {
            printf("Out of Registers\n");
            exit(1);
        }
        fprintf(ptr, "MOV R%d, %d\n", reg, root->val);
        return reg ;
    }

    int l = codeGen(root->left, ptr);
    int r = codeGen(root->right, ptr);

    switch(*(root->op)) {
        case '+' :  fprintf(ptr, "ADD R%d, R%d\n", l,r);
                    freeReg(r);
                    break;
        case '-' :  fprintf(ptr, "SUB R%d, R%d\n", l,r);
                    freeReg(r);
                    break;

        case '*' :  fprintf(ptr, "MUL R%d, R%d\n", l,r);
                    freeReg(r);
                    break;

        case '/' :  fprintf(ptr, "DIV R%d, R%d\n", l,r);
                    freeReg(r);
                    break;
    }
    return l ;
}


void printRes(int reg , FILE *ptr) {

    fprintf(ptr, "MOV [4096], R%d\n", reg);

    int r1 = getReg();
    if(r1 == -1) {
        printf("Out of Registers\n");
        exit(1);
    }

    fprintf(ptr, "MOV R%d, \"Write\"\n",r1);    
    
    fprintf(ptr, "PUSH R%d\n",r1);           //PUSH Function Code
    fprintf(ptr, "MOV R%d, -2\n", r1);
    fprintf(ptr, "PUSH R%d\n",r1);          //PUSH Argument 1 = -2(For Write)
    fprintf(ptr, "PUSH R%d\n",reg);         //PUSH Argument 2 = Data to be written
    fprintf(ptr, "PUSH R%d\n",r1); 
    fprintf(ptr, "PUSH R%d\n",r1); 

    fprintf(ptr, "CALL 0\n");

    fprintf(ptr, "POP R0\n");
    fprintf(ptr, "POP R%d\n", r1);
    fprintf(ptr, "POP R%d\n", r1);
    fprintf(ptr, "POP R%d\n", r1);
    fprintf(ptr, "POP R%d\n", r1);


    freeReg(r1);
}

void exitProg(FILE* ptr){
    int r = getReg();

    fprintf(ptr, "MOV R%d, \"Exit\"\nPUSH R%d\n", r, r);
    fprintf(ptr, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", r, r, r, r);
    fprintf(ptr, "CALL 0");

    freeReg(r);
}