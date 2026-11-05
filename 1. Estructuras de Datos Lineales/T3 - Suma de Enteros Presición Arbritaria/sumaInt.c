
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    short digit;
    struct Node *next;
} Node;


Node *createNode(short digit) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    newNode->digit = digit;
    newNode->next = NULL;

    return newNode;
}


void insertFront(Node **head, short digit) {
    Node *newNode = createNode(digit);

    newNode->next = *head;
    *head = newNode;
}


Node *readNumber(void) {
    Node *head = NULL;
    int character;

    do {
        character = getchar();
    } while (character != EOF && isspace(character));

    while (character != EOF && !isspace(character)) {
        if (character >= '0' && character <= '9') {
            insertFront(&head, (short)(character - '0'));
        }

        character = getchar();
    }

    return head;
}


Node *addNumbers(Node *first, Node *second) {
    Node *result = NULL;
    int carry = 0;

    while (first != NULL || second != NULL || carry != 0) {
        int sum = carry;

        if (first != NULL) {
            sum += first->digit;
            first = first->next;
        }

        if (second != NULL) {
            sum += second->digit;
            second = second->next;
        }

        insertFront(&result, (short)(sum % 10));

        carry = sum / 10;
    }

    return result;
}


void printNumber(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%hd", current->digit);
        current = current->next;
    }

    printf("\n");
}


void freeList(Node *head) {
    Node *current;

    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}


int main(void) {
    Node *first;
    Node *second;
    Node *result;

    first = readNumber();
    second = readNumber();

    result = addNumbers(first, second);

    printNumber(result);

    freeList(first);
    freeList(second);
    freeList(result);

    return 0;
}
