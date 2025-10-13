#include "symbolTable.h"
#include "exptree.h"

int bindAddress = STACK_BASE ;

struct Gsymbol* createSymbolNode(char* name, int type, int size) {
    struct Gsymbol * node = (struct Gsymbol *) malloc(sizeof(struct Gsymbol));

    node->name = name ;
    node->type = type ;
    node->size1 = size ;
    node->next = NULL ;
    node->binding = bindAddress ;
    bindAddress += size ;

    return node ;
}


struct Gsymbol * find(struct Gsymbol * head, char * name) {
    if(!head) return NULL;

    struct Gsymbol * temp = head;
    while(temp) {
        if(strcmp(temp->name,name) == 0) {
            return temp ;
        }
        temp = temp->next ;
    }

    return NULL ;
}


struct Gsymbol * insertTable(struct Gsymbol * head,char * name, int type, int size) {
    if(find(head,name) != NULL) {
        printf("Redeclaration of variable\n");
        exit(1);
    } 

    struct Gsymbol * temp = head ;
    struct Gsymbol * node = createSymbolNode(name,type,size); 

    if(temp == NULL) {
        head = node ;
        return head ;
    } 
    
    while(temp->next) {
        temp = temp->next ;
    }
    temp->next = node ;
    return head ;
}

void printSymbolTable(struct Gsymbol * head) {
    struct Gsymbol * node = head ;

    while(node) {
        printf("Name : %s, Address : %d, Type : %d\n",node->name,node->binding,node->type);
        node = node->next ;
    }
}