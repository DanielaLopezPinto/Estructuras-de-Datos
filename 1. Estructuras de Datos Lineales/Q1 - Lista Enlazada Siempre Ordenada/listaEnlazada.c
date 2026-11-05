#include <stdio.h>

//Estructura del Nodo
typedef struct Node {
    int data;
    struct Node* next;
} Node;


int main() {
    Node *head = NULL;
    int number;

    printf("Ingrese numeros enteros (0 oara terminar):\n");

    while (scanf("%d", &number) == 1 && number != 0) {
        orderedInsertion(&head, number);
    }

    printf("Lista enlazada ordenada:\n");
    printList(head);

    freeList(&head);

    return 0;
}


//Creación del Nodo
Node *createNode(int valor) {

    Node *new = malloc(sizeof(Node));

    if (new == NULL) {
        printf("Memory allocator failer\n");
        exit(1);
    }

    new->data = valor;
    new->next = NULL;

    return new;
}

// Insertar en orden
void orderedInsertion (Node **head, int value) {
    Node *new = createNode(value);

    if (*head == NULL || value < (*head)->data) {
        new->next = *head;
        *head = new;
        return;
    }
    
    Node *current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    new->next = current->next;
    current->next = new;
    
}

// Imprimir lista
void printList (Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Liberar lista
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