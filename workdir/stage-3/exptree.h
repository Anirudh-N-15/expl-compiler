#ifndef exptree_h
#define exptree_h

#define NO_VAL -1

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum nodetype {
    NUM_NODE      = 0,
    ID_NODE       = 1,
    READ_NODE     = 2,
    WRITE_NODE    = 3,
    ASSIGN_NODE   = 4,
    ADD_NODE      = 5,
    MINUS_NODE    = 6,
    MUL_NODE      = 7,
    DIV_NODE      = 8,
    CONNECT_NODE  = 9,
    IF_NODE       = 10,
    ELSE_NODE     = 11,
    WHILE_NODE    = 12,
    EXPR_NODE     = 13,
    EQ_NODE       = 14,
    LT_NODE       = 15,
    LE_NODE       = 16,
    GT_NODE       = 17,
    GE_NODE       = 18,
    NE_NODE       = 19
};


enum Datatype {
    INT_TYPE    = 0,
    BOOL_TYPE   = 1,
    NO_TYPE     = 2
};


struct tnode {
    int val;            // value of a number for NUM nodes.
    int type;           // type of variable
    char * varname;     // name of a variable for ID nodes
    int nodetype;       // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode * left, *right ;
};

struct tnode * createTreeNode(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r);

int checkOp(int nodeType);
int evaluate(struct tnode * root);
void inorder(struct tnode * root);

#endif