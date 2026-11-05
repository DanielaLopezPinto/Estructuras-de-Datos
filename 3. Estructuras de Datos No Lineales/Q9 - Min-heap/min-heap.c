
#include <stdio.h>

#define MAX 1000

// Intercambia dos valores
void intercambiar(int *a, int *b) {

    int aux = *a;
    *a = *b;
    *b = aux;
}


// Inserta un elemento manteniendo la regla MinHeap
void insertarMinHeap(int heap[], int *tam, int valor) {

    int i = *tam;

    heap[i] = valor;
    (*tam)++;

    // Compara el elemento con su padre
    while (i > 0) {

        int padre = (i - 1) / 2;

        if (heap[i] < heap[padre]) {

            intercambiar(&heap[i], &heap[padre]);

            i = padre;

        } else {
            break;
        }
    }
}


// Muestra el heap
void mostrarHeap(int heap[], int tam) {

    printf("\nMinHeap: ");

    for (int i = 0; i < tam; i++) {
        printf("%d ", heap[i]);
    }

    printf("\n");
}


int main() {

    int heap[MAX];
    int tam = 0;
    int cantidad;
    int valor;

    printf("Cuantos numeros desea ingresar? ");
    scanf("%d", &cantidad);

    if (cantidad < 0 || cantidad > MAX) {
        printf("Cantidad no valida.\n");
        return 1;
    }

    // Lee los numeros y los inserta en el MinHeap
    for (int i = 0; i < cantidad; i++) {

        printf("Ingrese un numero: ");
        scanf("%d", &valor);

        insertarMinHeap(heap, &tam, valor);
    }

    // Muestra el resultado
    mostrarHeap(heap, tam);

    return 0;
}
