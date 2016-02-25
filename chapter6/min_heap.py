import heapify

class MinHeap(Heap):
    def __init__(self, elements):
        super(MinHeap, self).__init__(elements)
        self.min_heapify()

    def min_heapify(self):
        for i in xrange(self.heap_size >> 1, 0, -1):
            min_heapify(self, i)

    def extract_min(self):
        if self.heap_size < 1:
            raise 'Heap underflow'

        bottom = self[i]
        self[1] = self[self.heap_size]
        self.heap_size -= 1
        self.min_heapify()
        return bottom

    def minimum(self):
        return self[1]

    def decrease_key(self, i, key):
        if key > self[i]:
            raise "new key is greater than current key"
        self[i] = key
        while i > 1 and self[parent(i)] > key:
            self[i] = self[parent(i)]
            i = parent(i)
        self[i] = key

    def insert(self, key):
        self.heap_size += 1
        self.length += 1
        self.elements.append(key)
        self.decrease_key(self.heap_size, key)

    def sort(self):
        for i in xrange(self.elements_length(), 1, -1):
            self.swap(1, i)
            self.heap_size -= 1
            min_heapify(self, 1)
        return self.elements

def parent(i):
    return i >> 1

def left(i):
    return i << 1

def right(i):
    return (i << 1) + 1
    
def min_heapify(A, i):
    l = left(i)
    r = right(i)

    if l <= A.heap_size and A[l] < A[i]:
        smallest = l
    else:
        smallest = i
    if r <= A.heap_size and A[r] < A[smallest]:
        smallest = r

    if smallest != i:
        A.swap(i, smallest)
        return min_heapify(A, smallest)

    return A

# min_heapify, compared to max_heapify - the run both at time O(lg n)

# Calling max_heapify when the element A[i] is larger than its children
# will make the procedure stop and return at that point.
# Since this is the the return point of the recursive procedure.