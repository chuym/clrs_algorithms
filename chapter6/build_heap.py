import heapify 

def build_max_heap(A):
    heap = Heap(A)
    for i in xrange(len(heap) >> 1, 0, -1):
        max_heapify(heap, i)
    return heap

# the loop goes from A.length / 2 to 1 because max_heapify guarantees
# that leaves for A[i] wil be lower than A[i], without regard of its
# parent.