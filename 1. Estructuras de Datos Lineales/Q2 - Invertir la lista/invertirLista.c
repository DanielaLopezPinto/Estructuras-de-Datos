#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node *next;
} Node;

Node* createNode (float value){

    Node* new = (Node*)malloc(sizeof(Node));

    if (new == NULL) {
        printf("Memory allocator failer\n");
        exit(1);
    }

    new->data= value;
    new->next= NULL;

    return new;
}


int main() {
    
    Node *head = NULL;
    Node *tail = NULL;

    float num;
    int cont = 0;

    printf("Ingrese numeros reales:\n");

    while (scanf("%f", &num) == 1) {

        insertarFinal(&head, &tail, num);

        if (num == -1.0f) {
            cont++;
        }
        if (cont == 3) {
            break;
        }
    }

    invertirLista(&head);

    printf("\nLista invertida:\n");
    imprimirLista(head);

    liberarLista(&head);

    return 0;
}

// Insertal al final FIFO
void insertFinal(Node **head, Node **tail, float value) {

    Node*new = createNode(value);

    if (*head == NULL) {
        *head = new;
        *tail = new;
    }
    else  {
        (*tail)->next = new;
        *tail = new;
    }
}

void invertList (Node **head) {
    
    Node *before = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = before;

        before = current;
        current = next;
    }

    *head = before;
}

void printList (Node *head) {

    Node *current = head;

    while (current != NULL) {
        printf("%.2f -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void freeList(Node **head) {
    Node *current = *head;
    Node *nextNode;

    while (current != NULL) {
        nextNode = current;
        current = current->next;
        free(nextNode);
    }
    *head = NULL;
}


