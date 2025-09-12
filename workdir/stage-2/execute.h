#ifndef execute_h
#define execute_h 


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "exptree.h"

int getReg();
int freeReg(int r);

void writeToTerminal(FILE * op, int r);
void readFromTerminal(FILE * op, char ch);
int exprEvaluate(FILE * op, struct tnode * root);


void finalOutput(struct tnode * root, FILE * op);
int codeGen(struct tnode * root, FILE * op);
void writeToTerminal(FILE * op, int r);
void exitProg(FILE * op);

int evaluate(struct tnode * root);
void evaluator(struct tnode * root);

#endif