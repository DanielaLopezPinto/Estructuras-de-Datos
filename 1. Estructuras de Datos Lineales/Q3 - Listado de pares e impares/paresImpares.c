
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode (int value) {

    Node *new = malloc(sizeof(Node));

    if (new == NULL) {
        printf("Memory allocator failer\n");
        exit(1);
    }

    new->data = value;
    new->next = NULL;

    return new;
}

void insertFinal(Node **head, Node **tail, int value) {

    Node *new = createNode(value);

    if (*head == NULL) {
        *head = new;
        *tail = new;

    } else {
        (*tail)->next = new;
        *tail = new;
    }
}

void agregarNodo (Node **head, Node **tail, Node *new) {

    new->next = NULL;

    if (*head == NULL) {
        *head = new;
        *tail = new;
    }
    else {
        (*tail)->next = new;
        *tail = new;
    }
}

void separarLista (Node *original, Node **even, Node **tailEven, Node **odd, Node **tailOdd) {

    Node *current = original;
    Node *next;

    while (current != NULL) {

        next = current->next;
        current->next = NULL;

        if (current->data % 2 == 0) {
            agregarNodo(even, tailEven, current);
        }
        else {
            agregarNodo(odd, tailOdd, current);
        }

        current = next;
    }
}

void printList(Node *head) {

    Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}


void freeList(Node **head) {

    Node *current = *head;
    Node *newNode;

    while (current != NULL) {
        newNode = current;
        current = current->next;
        free(newNode);
    }

    *head = NULL;
}

int main() {

    Node *head = NULL;
    Node *tail = NULL;

    Node *even = NULL;
    Node *tailEven = NULL;

    Node *odd = NULL;
    Node *tailOdd = NULL;

    int numero;

    printf("Ingrese numeros enteros (0 para terminar):\n");

    
    while (scanf("%d", &numero) == 1 && numero != 0) {
        insertFinal(&head, &tail, numero);
    }

    // Separar la lista
    separarLista(head, &even, &tailEven, &odd, &tailOdd);

    // Mostrar las listas resultantes
    printf("\nLista de numeros pares:\n");
    printList(even);

    printf("\nLista de numeros impares:\n");
    printList(odd);

    freeList(&even);
    freeList(&odd);

    return 0;
}
