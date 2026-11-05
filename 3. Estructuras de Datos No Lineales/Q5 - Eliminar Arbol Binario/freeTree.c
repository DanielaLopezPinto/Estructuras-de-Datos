
#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo del arbol
typedef struct node {
    short data;
    struct node *left;
    struct node *right;
} tipoNodo, *nodo;


// Estructura del arbol
typedef struct {
    nodo root;
} tipoArbol, *arbolBinario;


// Prototipos
nodo crearNodo(short);
nodo construirPreOrden();

arbolBinario crearArbol();
arbolBinario crearPreOrden();

void mostrarPreOrden(nodo actual);
void eliminarArbol(arbolBinario arbol);
void eliminarNodos(nodo actual);


int main() {

    arbolBinario arbol = crearPreOrden();
    printf("\nRecorrido PreOrder: ");
    mostrarPreOrden(arbol->root);
    printf("\n");
    eliminarArbol(arbol);
    return 0;
}

// Crea un nuevo nodo
nodo crearNodo(short valor) {

    nodo nuevo = malloc(sizeof(tipoNodo));
    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
    }
    nuevo->data = valor;
    nuevo->left = NULL;
    nuevo->right = NULL;

    return nuevo;
}

// Crea un arbol vacio
arbolBinario crearArbol() {
    arbolBinario nuevo = malloc(sizeof(tipoArbol));
    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
    }
    nuevo->root = NULL;
    return nuevo;
}

// Construye el arbol en preorden
nodo construirPreOrden() {
    short valor;
    printf("Ingrese un valor (0 para NULL): ");
    scanf("%hd", &valor);
    if (valor == 0) {
        return NULL;
    }
    nodo nuevo = crearNodo(valor);
    nuevo->left = construirPreOrden();
    nuevo->right = construirPreOrden();
    return nuevo;
}


// Crea el arbol mediante preorden
arbolBinario crearPreOrden() {
    arbolBinario arbol = crearArbol();
    arbol->root = construirPreOrden();
    return arbol;
}

// Muestra el recorrido en preorden
void mostrarPreOrden(nodo actual) {
    if (actual == NULL) {
        return;
    }
    printf("%hd ", actual->data);
    mostrarPreOrden(actual->left);
    mostrarPreOrden(actual->right);
}


// Elimina los nodos del arbol
void eliminarNodos(nodo actual) {

    if (actual == NULL) {
        return;
    }
    eliminarNodos(actual->left);
    eliminarNodos(actual->right);

    free(actual);
}


// Libera toda la memoria del arbol
void eliminarArbol(arbolBinario arbol) {

    if (arbol == NULL) {
        return;
    }
    eliminarNodos(arbol->root);
    free(arbol);
}
