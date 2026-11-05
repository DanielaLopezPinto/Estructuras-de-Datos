#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un paciente
typedef struct {
    int ID;
    int category;
} pacient;

// Estructura para el Min-Heap
typedef struct {
    pacient *elements;
    int cap;
    int tam;
} MinHeap;

//Crea el min-heap con una capacidad inicial
MinHeap* createHeap(int cap) {
    MinHeap *heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->cap = cap;
    heap->tam = 0;
    heap->elements = (pacient*) malloc (cap * sizeof(pacient));
    return heap;
}

// Intercambia dos pacientes en el heap
void swap(pacient *a, pacient *b) {
    pacient aux = *a;
    *a = *b;
    *b = aux;
}

// Mantiene la propiedad del min-heap después de insertar un nuevo paciente
void siftUp(MinHeap *h, int i) {
    int father = (i - 1) / 2;

    while (i > 0 && h->elements[i].category < h->elements[father].category) {
            swap(&h->elements[i], &h->elements[father]);
            i = father; 
            father = (i - 1) / 2;
        
    }
}

// Inserta un paciente en el min-heap
void insert(MinHeap *h, int ID, int category) {
    // Redimensionar el heap si se llena (realloc)
    if (h->tam == h->cap) {
        h->cap *= 2;
        h->elements = (pacient*) realloc(h->elements, h->cap * sizeof(pacient));
    }

    h->elements[h->tam].ID = ID; 
    h->elements[h->tam].category = category;
    siftUp(h, h->tam);
    h->tam++;
}

// Mantiene la propiedad del min-heap después de atender al paciente con mayor prioridad
void siftDown(MinHeap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->tam && h->elements[left].category < h->elements[smallest].category) {
        smallest = left;
    }

    if (right < h->tam && h->elements[right].category < h->elements[smallest].category) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&h->elements[i], &h->elements[smallest]);
        siftDown(h, smallest);
    }
}

// Extrae el paciente con mayor prioridad
pacient extractMin(MinHeap *h) {
    pacient root = h->elements[0];
    h->elements[0] = h->elements[h->tam - 1];
    h->tam--;
    siftDown(h, 0);
    return root;
}

int main(){

    FILE *file = fopen("triage_data.txt", "r");
    if (!file) {
        printf("Error!: the file could not be opened.\n");
        return 1;
    }

    MinHeap *h = createHeap(10);
    char buffer[50];
    
    // Tokenizar
    while (fscanf(file, "%s", buffer) != EOF) {
        if (strcmp(buffer, "000000") == 0) {
            //El medico atiende un paciente si hay pacientes en espera en el heap
            if (h->tam > 0) {
                pacient seen = extractMin(h);
                printf("Paciente atendido: ID=%d, Categoria=%d\n", seen.ID, seen.category);
            }

        } else {
            // El buffer leido es la cedula, ahora se lee la categoria
            int ID = atoi(buffer);
            int category;
            fscanf(file, "%d", &category);

            if (category != 4) {
                insert(h, ID, category);
            }
        }
    }
    // Liberar la memoria dinámica reservada
    fclose(file);
    free(h->elements);
    free(h);

    return 0;
}