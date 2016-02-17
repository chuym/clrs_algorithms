class Heap:
    def __init__(self, elements):
        self.elements = list(elements)
        self.heap_size = len(elements)
        self.length = len(elements)

    def elements_length(self):
        return self.length

    def swap(self, a, b):
        temp = self[a]
        self[a] = self[b]
        self[b] = temp

    def maximum(self):
        return self[1]

    def max_heapify(self):
        for i in xrange(self.heap_size >> 1, 0, -1):
            max_heapify(self,i)

    def extract_max(self):
        if self.heap_size < 1:
            raise 'Heap underflow'

        top = self[1]
        self[1] = self[self.heap_size]
        self.heap_size = self.heap_size - 1
        self.max_heapify()
        return top

    def increase_key(self, i, key):
        if key < self[i]:
            raise "new key is smaller than current key"
        self[i] = key
        while i > 1 and self[parent(i)] < self[i]:
            self.swap(i, parent(i))
            i = parent(i)

    def insert(self, key):
        self.heap_size += 1
        self.length += 1
        self.elements.append(key)
        print self.elements
        self.increase_key(self.heap_size, key)

    def __getitem__(self, key):
        return self.elements[key-1]

    def __setitem__(self, key, value):
        self.elements[key-1] = value

    def __len__(self):
        return self.heap_size

    def __str__(self):
        return str(self.elements)

def parent(i):
    return i >> 1

def left(i):
    return i << 1

def right(i):
    return (i << 1) + 1
    
def max_heapify(A, i):
    l = left(i)
    r = right(i)

    if l <= A.heap_size and A[l] > A[i]:
        largest = l
    else:
        largest = i
    if r <= A.heap_size and A[r] > A[largest]:
        largest = r

    if largest != i:
        A.swap(i, largest)
        return max_heapify(A, largest)

    return A

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
        temp = A[i]
        A[i] = A[smallest]
        A[smallest] = temp
        return min_heapify(A, smallest)

    return A

# min_heapify, compared to max_heapify - the run both at time O(lg n)

# Calling max_heapify when the element A[i] is larger than its children
# will make the procedure stop and return at that point.
# Since this is the the return point of the recursive procedure.