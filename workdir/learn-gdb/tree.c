#include <string.h>

struct tnode * createTree(char * symbol,struct  tnode * left,struct tnode * right) {
    struct tnode * treeNode = (struct tnode *) malloc(sizeof(struct tnode));
    treeNode->symbol = strdup(symbol);
    treeNode->left = left ;
    treeNode->right = right ;

    return treeNode ;
}

void infixtoprefix(struct tnode * root) {
    if(root) {
        printf("%s ",root->symbol);
        infixtoprefix(root->left);
        infixtoprefix(root->right);
    }
}