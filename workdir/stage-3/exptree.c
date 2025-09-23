#include "exptree.h"

static int nums[26] = {0} ;

int checkOp(int nodeType) {
    return (nodeType == ADD_NODE || nodeType == MUL_NODE || nodeType == MINUS_NODE || 
            nodeType == DIV_NODE || nodeType == NE_NODE || nodeType == EQ_NODE ||
            nodeType == LT_NODE || nodeType == LE_NODE || nodeType == GT_NODE ||
            nodeType == GE_NODE || nodeType == ASSIGN_NODE);
}



struct tnode * createTreeNode(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r) {
    struct tnode * temp = malloc(sizeof(struct tnode));

    if(checkOp(nodetype) &&  (( l && l->type != INT_TYPE) || (r &&  r->type != INT_TYPE ))) {
        perror("type mismatch");
        exit(1);
    }

    temp->val = val ;
    temp->varname = varname ;

    temp->type = type ;
    temp->nodetype = nodetype ;

    temp->left = l ;
    temp->right = r ;

    return temp ;
}

void inorder(struct tnode * root) {
    if(root ) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int evaluate(struct tnode * root) {
    if(root == NULL) {
        return -1 ;
    }
    switch(root->nodetype) {
        case NUM_NODE : {
            return root->val ;
        }

        case ID_NODE : {
            return nums[root->varname[0] - 'a'] ;
        }

        case READ_NODE : {
            scanf("%d",&nums[root->left->varname[0] - 'a']);
            break ;
        }
        case WRITE_NODE : {
            printf("%d\n",evaluate(root->left));
            break;
        }

        case ADD_NODE : {
            return evaluate(root->left) + evaluate(root->right) ;
        }
        case MINUS_NODE : {
            return evaluate(root->left) - evaluate(root->right) ;
        }
        case DIV_NODE : {
            return evaluate(root->left) / evaluate(root->right) ;
        }
        case MUL_NODE : {
            return evaluate(root->left) * evaluate(root->right) ;
        }
        case NE_NODE : {
            return (evaluate(root->left) != evaluate(root->right)) ;
        }
        case EQ_NODE : {
            return evaluate(root->left) == evaluate(root->right) ;
        }
        case GT_NODE : {
            return evaluate(root->left) > evaluate(root->right) ;
        }
        case GE_NODE : {
            return evaluate(root->left) >= evaluate(root->right) ;
        }
        case LE_NODE : {
            return evaluate(root->left) <= evaluate(root->right) ;
        }
        case LT_NODE : {
            return evaluate(root->left) < evaluate(root->right) ;
        }
        case ASSIGN_NODE : {
            nums[root->left->varname[0] - 'a'] = evaluate(root->right) ;
            return -1;
        }

        case CONNECT_NODE : {
            evaluate(root->left);
            evaluate(root->right);
            return -1;
        }

        case IF_NODE : {
            if(evaluate(root->left)) {
                if(root->right->nodetype == ELSE_NODE) {
                    evaluate(root->right->left) ;
                } else {
                    evaluate(root->right) ;
                }
            } else {
                if(root->right->nodetype == ELSE_NODE) {
                    evaluate(root->right->right);
                } 
            }
            break;
        }
        case WHILE_NODE : {
            while(evaluate(root->left)) {
                evaluate(root->right) ;
            } 
            break ;
        }
    }
    return 0 ;
}


