import dary_heap
from math import ceil

class MaxHeap(Heap):
    def __init__(self, elements, **kwargs):
        super(MaxHeap, self).__init__(elements, **kwargs)
        self.max_heapify()
    
    def max_heapify(self):
        for i in xrange(self.heap_size / self.arity, 0, -1):
            max_heapify(self, i)

    def extract_max(self):
        if self.heap_size < 1:
            raise "Heap underflow"

        top = self[1]
        self[1] = self[self.heap_size]
        self.heap_size -= 1
        self.length -= 1
        self.elements.pop()
        self.max_heapify()
        return top

    def maximum(self):
        return self[1]

    # Invariant:
    # At the start of the while loop, self[parent(i)] >= self[left(i)] and
    # self[parent(i)] >= self[right(i)] and self[1..heap_size] is a max heap
    # but there may or may not be a violation with the key self[i] that was just
    # inserted
    #
    # In the while loop, we check if i is at the root, if it is, there is nothing
    # more to do and return. We also check if self[i] violates the max heap property
    # by comparing it to its parent.
    # If there is no violation, there's nothing more to do and self[1..heap_size] is
    # a max heap. If there is a violation, we swap keys with its parent and iterate
    # the while loop until we reach the root or there are no more max heap property
    # violations.
    def increase_key(self, i, key):
        if key < self[i]:
            raise "new key is smaller than current key"
        self[i] = key
        while i > 1 and self[self.parent(i)] < key:
            self[i] = self[self.parent(i)]
            i = self.parent(i)
        self[i] = key

    def insert(self, key):
        self.heap_size += 1
        self.length += 1
        self.elements.append(key)
        self.increase_key(self.heap_size, key)

    def delete(self, i):
        self.heap_size -= 1
        self.length -= 1
        self.elements.pop(i - 1)
        self.max_heapify()

    def sort(self):
        for i in xrange(heap.elements_length(), 1, -1):
            heap.swap(1, i)
            heap.heap_size = heap.heap_size - 1
            max_heapify(heap, 1)

        return heap.elements

def max_heapify(A, i):
    children = A.children(i)

    largest = reduce(lambda c, v: v if v <= A.heap_size and A[v] > A[c] else c, children, i)

    if largest != i:
        A.swap(i, largest)
        return max_heapify(A, largest)

    return A