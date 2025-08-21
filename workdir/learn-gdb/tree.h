typedef struct tnode {
    char * symbol ;
    struct tnode * left, *right ;
}tnode;

void infixToPrefix(struct tnode * root);

struct tnode * createTree(char * symbol,struct  tnode * left,struct tnode * right);