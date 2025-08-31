#ifndef exptree_h
#define epxtree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct tnode {
    int val;
    char * op;
    struct tnode *left, *right ;
};

struct tnode* createLeafNode(int n);
struct tnode* createOperatorNode(char op, struct tnode * left, struct tnode * right);

int evaluate(struct tnode * t);

void prefix(struct tnode * root);
void postfix(struct tnode * root);
void infix(struct tnode * root);

void execGen(struct tnode * root, FILE * ptr);
int getReg();
int freeReg(int reg);
int codeGen(struct tnode * root, FILE * ptr);
void printRes(int reg, FILE  * ptr);
void exitProg(FILE *ptr);

#endif

