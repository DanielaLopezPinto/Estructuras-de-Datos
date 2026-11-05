#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} list;

list* createList (void) {
    list *n = malloc(sizeof(list));
    n->head = NULL;
    n->tail = NULL;

    return n;
}

int cont (list *n, int value) {
    Node *current = n -> head;
    while (current != NULL){
        if (current->data == value) 
        return 1;
        current = current->next;         
    }

    return 0;
}

void insertList (list *n, int value) {
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;

    if (n->head == NULL) {
        n->head = new;
        n->tail = new;
    } 
    else {
        n->tail->next = new;
        n->tail = new;
    }
} 

void printList (list *n) {
    Node *current = n->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void destroyList (list *n) {
    Node *current = n->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(n);
}

list* fusionarUnicos(list *l1, list *l2) {
    list *r = createList();

    Node *current = l1->head;
    while (current != NULL) {
        if (!cont(r, current->data)){
            insertList(r, current->data);
        }
        current = current->next;
    }

    current = l2->head;
    while (current != NULL) {
        if(!cont(l1, current->data) && !cont(r, current->data)) {
            insertList(r, current->data);
        }
        current = current->next;
    }
    return r;

}

int main(void){

    list *l1 = createList();
    list *l2 = createList();

    int value;
    
    printf("Ingrese la primer lista de numeros (-1 para terminar):");
    
    while (scanf("%d", &value) == 1 && value != -1) {
        insertList(l1, value);
    }

    printf("Ingrese la segunda lista de numeros (-1 para terminar):");
    
    while (scanf("%d", &value) == 1 && value != -1) {
        insertList(l2, value);
    }

    list *l3 = fusionarUnicos(l1, l2);

    printList(l3);

    destroyList(l1);
    destroyList(l2);
    destroyList(l3);

    return 0;
}

