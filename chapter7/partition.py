def quicksort(A):
    _quicksort(A, 0, len(A) - 1)
    
def _quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        _quicksort(A, p, q - 1)
        _quicksort(A, q + 1, r)

def partition(A, p, r):
    pivot = A[r]
    i = p - 1
    for j in xrange(p, r):
        if A[j] <= pivot:
            i += 1
            swap(A, i, j)

    swap(A, i + 1, r)

    return i + 1

def swap(A, i, j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp