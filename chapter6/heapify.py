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

    def __getitem__(self, key):
        return self.elements[key-1]

    def __setitem__(self, key, value):
        self.elements[key-1] = value

    def __len__(self):
        return self.heap_size

    def __str__(self):
        return str(self.elements)

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