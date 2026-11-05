
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

int main(void) {

    int numbers[MAX_SIZE];
    int size;

    Node *head = NULL;
    Node *tail = NULL;

    printf("Ingrese el numero de elementos (1-100): ");

    if (scanf("%d", &size) != 1 ||
        size < 1 || size > MAX_SIZE) {
        printf("Invalid size\n");
        return EXIT_FAILURE;
    }

    printf("Escriba los numeros:\n");

    for (int i = 0; i < size; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input\n");
            freeList(&head);
            return EXIT_FAILURE;
        }
    }

    buildUniqueList(numbers, size, &head, &tail);

    printf("Numeros que aparecen extactamente una vez:\n");
    printList(head);

    freeList(&head);

    return 0;
}


void insertEnd(Node **head, Node **tail, int value) {
    Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}


int countOccurrences(int numbers[], int size, int value) {
    
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] == value) {
            count++;
        }
    }

    return count;
}

void buildUniqueList(int numbers[], int size, Node **head, Node **tail) {

    for (int i = 0; i < size; i++) {
        if (countOccurrences(numbers, size, numbers[i]) == 1) {
            insertEnd(head, tail, numbers[i]);
        }
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
