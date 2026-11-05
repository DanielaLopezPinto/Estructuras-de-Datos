#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo del árbol
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} tipoNodo, *nodo;

// Estructura del árbol binario
typedef struct {
    nodo root;
} tipoArbol, *arbolBinario;


nodo crearNodo(int valor);
arbolBinario crearArbolBinario();
arbolBinario crearArbolBST();
nodo insertarBST(nodo raiz, int valor);
void preorden(arbolBinario tree);
void recorridoPreorden(nodo raiz);
void inorden(arbolBinario tree);
void recorridoInorden(nodo raiz);
void postorden(arbolBinario tree);
void recorridoPostorden(nodo raiz);

int main(void) {
    arbolBinario arbol = crearArbolBST();

    int valor;

    printf("Ingrese valores para el BST (-1 para terminar):\n");

    while (scanf("%d", &valor) == 1 && valor != -1) {
        arbol->root = insertarBST(arbol->root, valor);
    }

    printf("\nRecorrido en preorden: ");
    preorden(arbol);

    printf("\nRecorrido en inorden: ");
    inorden(arbol);

    printf("\nRecorrido en postorden: ");
    postorden(arbol);

    printf("\n");
    return 0;
}

nodo crearNodo(int valor) {
    nodo nuevoNodo = malloc(sizeof(tipoNodo));

    if (nuevoNodo == NULL) {
        printf("Error al reservar memoria.\n");
    }

    nuevoNodo->data = valor;
    nuevoNodo->left = NULL;
    nuevoNodo->right = NULL;

    return nuevoNodo;
}

arbolBinario crearArbolBinario() {
    arbolBinario nuevoArbol = malloc(sizeof(tipoArbol));

    if (nuevoArbol == NULL) {
        printf("Error al reservar memoria.\n");
    }

    nuevoArbol->root = NULL;
    return nuevoArbol;
}

arbolBinario crearArbolBST() {
    return crearArbolBinario();
}

// Inserta un valor respetando las reglas del BST
nodo insertarBST(nodo raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->data) {
        raiz->left = insertarBST(raiz->left, valor);
    } else if (valor > raiz->data) {
        raiz->right = insertarBST(raiz->right, valor);
    }

    return raiz;
}

// Recorrido preorden: raiz, izquierda, derecha
void preorden(arbolBinario tree) {
    if (tree != NULL) {
        recorridoPreorden(tree->root);
    }
}

void recorridoPreorden(nodo raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->data);
        recorridoPreorden(raiz->left);
        recorridoPreorden(raiz->right);
    }
}

// Recorrido inorden: izquierda, raiz, derecha
void inorden(arbolBinario tree) {
    if (tree != NULL) {
        recorridoInorden(tree->root);
    }
}

void recorridoInorden(nodo raiz) {
    if (raiz != NULL) {
        recorridoInorden(raiz->left);
        printf("%d ", raiz->data);
        recorridoInorden(raiz->right);
    }
}

// Recorrido postorden: izquierda, derecha, raiz
void postorden(arbolBinario tree) {
    if (tree != NULL) {
        recorridoPostorden(tree->root);
    }
}

void recorridoPostorden(nodo raiz) {
    if (raiz != NULL) {
        recorridoPostorden(raiz->left);
        recorridoPostorden(raiz->right);
        printf("%d ", raiz->data);
    }
}