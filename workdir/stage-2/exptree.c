#include "exptree.h"

struct tnode * createLeafNode(int type, char * varname, int val) {
    struct tnode * temp = malloc(sizeof(struct tnode));

    temp->type = type ;
    temp->nodetype = LEAF_NODE ;
    temp->val = val ;
    temp->varname = varname ;

    temp->left = NULL ;
    temp->right = NULL ;

    return temp ;
}

struct tnode * createOperatorNode(int nodetype, struct tnode * left, struct tnode * right) {
    struct tnode * temp = malloc(sizeof(struct tnode));
    temp->nodetype = nodetype ;
    temp->type = INTERNAL_TYPE ;
    temp->left = left ;
    temp->right = right ;

    return temp ;
}

struct tnode * createAssignNode(struct tnode * left, struct tnode * right) {
    struct tnode * temp = malloc(sizeof(struct tnode));

    temp->nodetype = ASSIGN_NODE ;
    temp->val = 0;
    temp->varname = NULL ; 
    temp->left = left ;
    temp->right = right ;


    return temp ;
}

struct tnode * createReadNode(struct tnode * idNode) {
    struct tnode * temp = malloc(sizeof(struct tnode));

    temp->nodetype = READ_NODE ;
    temp->type = INTERNAL_TYPE ;
    temp->val = 0 ;
    temp->varname = NULL ;
    temp->right = NULL ;

    temp->left = idNode ;   //Will be assigning the id to be read to the left of temp node

    return temp ;
}

struct tnode * createWriteNode(struct tnode * exprNode) {
    struct tnode * temp = malloc(sizeof(struct tnode));

    temp->nodetype = WRITE_NODE ;
    temp->type = INTERNAL_TYPE ;
    temp->left = exprNode ;

    temp->right = NULL ;
    temp->val  = 0;
    temp->varname = NULL ;

    return temp ;
}

struct tnode * createConnecterNode(struct tnode * left, struct tnode * right) {
    struct tnode * temp = malloc(sizeof(struct tnode ));

    temp->left = left ;
    temp->right = right ;
    temp->nodetype = CONNECT_NODE ;
    temp->type = INTERNAL_TYPE ;

    temp->val = 0;
    temp->varname = NULL ;

    return temp ;
}
