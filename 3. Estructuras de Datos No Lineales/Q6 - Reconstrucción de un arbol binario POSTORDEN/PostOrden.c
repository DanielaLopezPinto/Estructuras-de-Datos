#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Estructura del nodo del árbol
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tipoNodo, *nodo;

// Estructura del árbol binario
typedef struct
{
    nodo root;
} tipoArbol, *arbolBinario;

nodo crearNodo(int valor);
arbolBinario crearArbolBinario();
arbolBinario crearArbolPostorden();

nodo construirPostorden(int valores[], int *indice);

void preorden(arbolBinario tree);
void recorridoPreorden(nodo raiz);

void postorden(arbolBinario tree);
void recorridoPostorden(nodo raiz);

void inorden(arbolBinario *tree);
void recorridoInorden(nodo raiz);

void eliminarArbol(arbolBinario *tree);

int main(void)
{
    arbolBinario arbol = crearArbolPostorden();

    printf("\nRecorrido en preorden: ");
    preorden(arbol);

    printf("\nRecorrido en postorden: ");
    postorden(arbol);

    printf("\n");
    return 0;
}

nodo crearNodo(int valor)
{
    nodo nuevoNodo = malloc(sizeof(tipoNodo));

    if (nuevoNodo == NULL)
    {
        printf("Error al reservar memoria.\n");
        exit(EXIT_FAILURE);
    }

    nuevoNodo->data = valor;
    nuevoNodo->left = NULL;
    nuevoNodo->right = NULL;

    return nuevoNodo;
}

arbolBinario crearArbolBinario()
{
    arbolBinario nuevoArbol = malloc(sizeof(tipoArbol));

    if (nuevoArbol == NULL)
    {
        printf("Error al reservar memoria.\n");
        exit(EXIT_FAILURE);
    }

    nuevoArbol->root = NULL;
    return nuevoArbol;
}

// Lee los datos en postorden con centinela 0
arbolBinario crearArbolPostorden()
{
    int valores[MAX];
    int cantidad = 0;
    int valor;

    printf("Ingrese los valores en postorden con centinela 0:\n");

    while (scanf("%d", &valor) == 1)
    {
        if (cantidad == MAX)
        {
            printf("Se alcanzo el limite de valores.\n");
            exit(EXIT_FAILURE);
        }

        valores[cantidad++] = valor;

        /*  EOF permite terminar la entrada.
            El centinela 0 representa nodos vacios,
            por eso no se usa para terminar la lectura.*/
    }

    if (cantidad == 0)
    {
        printf("No se ingresaron valores.\n");
        exit(EXIT_FAILURE);
    }

    int indice = cantidad - 1;

    arbolBinario arbol = crearArbolBinario();
    arbol->root = construirPostorden(valores, &indice);

    if (indice != -1)
    {
        printf("La secuencia no representa un arbol valido.\n");
        exit(EXIT_FAILURE);
    }

    return arbol;
}

// Reconstruye el arbol leyendo la secuencia al reves
nodo construirPostorden(int valores[], int *indice)
{
    if (*indice < 0)
    {
        printf("Secuencia incompleta.\n");
        exit(EXIT_FAILURE);
    }

    int valor = valores[(*indice)--];

    if (valor == 0)
    {
        return NULL;
    }

    nodo nuevoNodo = crearNodo(valor);

    // Al leer al reves, primero se construye el subarbol derecho y luego el izquierdo.
    nuevoNodo->right = construirPostorden(valores, indice);
    nuevoNodo->left = construirPostorden(valores, indice);

    return nuevoNodo;
}

void preorden(arbolBinario tree)
{
    if (tree != NULL)
    {
        recorridoPreorden(tree->root);
    }
}

void recorridoPreorden(nodo raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->data);
        recorridoPreorden(raiz->left);
        recorridoPreorden(raiz->right);
    }
}

void postorden(arbolBinario tree)
{
    if (tree != NULL)
    {
        recorridoPostorden(tree->root);
    }
}

void recorridoPostorden(nodo raiz)
{
    if (raiz != NULL)
    {
        recorridoPostorden(raiz->left);
        recorridoPostorden(raiz->right);
        printf("%d ", raiz->data);
    }
}
