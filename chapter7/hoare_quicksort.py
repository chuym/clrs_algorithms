def quicksort(A):
    _quicksort(A, 0, len(A) - 1)

def _quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        _quicksort(A, p, q)
        _quicksort(A, q + 1, r)

def partition(A, p, r):
    x = A[p]
    i = p - 1
    j = r + 1

    while True:
        while True:
            j = j - 1
            if A[j] <= x:
                break

        while True:
            i = i + 1
            if A[i] >= x:
                break

        if i < j:
            A[i], A[j] = A[j], A[i]
        else:
            return j
