# Mantiene la propiedad del MinHeap hacia abajo
def min_siftDown(heap, n, i):
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    # Compara por frecencia (
    if left < n and heap[left][0] < heap[smallest][0]:
        smallest = left
    if right < n and heap[right][0] < heap[smallest][0]:
        smallest = right
        
    if smallest != i:
        heap[i], heap[smallest] = heap[smallest], heap[i]
        min_siftDown(heap, n, smallest)

# Mantiene la propiedad del MinHeap hacia arriba
def min_siftUp(heap, i):
    parent = (i - 1) // 2
    if i > 0 and heap[i][0] < heap[parent][0]:
        heap[i], heap[parent] = heap[parent], heap[i]
        min_siftUp(heap, parent)