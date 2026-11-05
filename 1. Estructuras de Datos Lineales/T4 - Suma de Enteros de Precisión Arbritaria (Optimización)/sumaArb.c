#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BASE 10000

typedef struct Node {
    short data;
    struct Node *next;
} Node;



Node *createNode(short data) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertFront(Node **head, short data) {
    Node *newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

/* Los numeros se insertan al final de la lista (derecha a izquierda)
para poder sumar primero unidades y mantener el orden de la suma*/
void insertEnd(Node **head, Node **tail, short data) {
    Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void freeList(Node *head) {
    Node *current;

    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}

Node *readNumber(void) {
    Node *digits = NULL;
    Node *blocks = NULL;
    Node *tail = NULL;
    Node *current;

    int character;
    int count = 0;
    int block = 0;
    int multiplier = 1;

    do {
        character = getchar();
    } while (character != EOF && isspace(character));

    while (character != EOF && !isspace(character)) {
        if (character >= '0' && character <= '9') {
            insertFront(&digits, (short)(character - '0'));
        }

        character = getchar();
    }


    current = digits;

    while (current != NULL) {
        block += current->data * multiplier;
        multiplier *= 10;
        count++;

        if (count == 4) {
            insertEnd(&blocks, &tail, (short)block);

            block = 0;
            multiplier = 1;
            count = 0;
        }

        current = current->next;
    }

    if (count > 0) {
        insertEnd(&blocks, &tail, (short)block);
    }

    freeList(digits);

    return blocks;
}


Node *addNumbers(Node *first, Node *second) {
    Node *result = NULL;
    int carry = 0;

    while (first != NULL || second != NULL || carry != 0) {
        int sum = carry;

        if (first != NULL) {
            sum += first->data;
            first = first->next;
        }

        if (second != NULL) {
            sum += second->data;
            second = second->next;
        }

        insertFront(&result, (short)(sum % BASE));

        carry = sum / BASE;
    }

    return result;
}

Node *removeLeadingZeros(Node *head) {
    while (head != NULL && head->data == 0 && head->next != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}


void printNumber(Node *head) {
    Node *current = head;

    if (current == NULL) {
        printf("0\n");
        return;
    }

    printf("%hd", current->data);
    current = current->next;

    while (current != NULL) {
        printf("%04hd", current->data);
        current = current->next;
    }

    printf("\n");
}


int main(void) {
    Node *first;
    Node *second;
    Node *result;

    first = readNumber();
    second = readNumber();

    result = addNumbers(first, second);

    result = removeLeadingZeros(result);

    printNumber(result);

    freeList(first);
    freeList(second);
    freeList(result);

    return 0;
}