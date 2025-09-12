#ifndef exptree_h
#define exptree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


enum nodetype {
    LEAF_NODE = 0,
    READ_NODE = 1,
    WRITE_NODE = 2,
    ASSIGN_NODE = 3,
    ADD_NODE = 4,
    MINUS_NODE = 5,
    MUL_NODE = 6,
    DIV_NODE =7,
    CONNECT_NODE = 8,
};

enum Datatype {
    INTERNAL_TYPE = 0,
    INT_TYPE = 1,
    ID_TYPE = 2
};


struct tnode {
    int val;            // value of a number for NUM nodes.
    int type;           // type of variable
    char * varname;     // name of a variable for ID nodes
    int nodetype;       // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode * left, *right ;
};

struct tnode * createLeafNode(int type , char * c,int val);
struct tnode * createOperatorNode(int nodetype, struct tnode  * left, struct tnode * right);

struct tnode * createReadNode(struct tnode * idNode);
struct tnode * createWriteNode(struct tnode * exprNode);
struct tnode * createAssignNode(struct tnode * left, struct tnode * right);
struct tnode * createConnecterNode(struct tnode * left, struct tnode * right);

int evaluate(struct tnode * root);

#endif