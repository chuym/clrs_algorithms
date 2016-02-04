def left(i):
    return i << 1

def right(i):
    return (i << 1) + 1
    
def max_heapify(A, i):
    l = left(i)
    r = right(i)


    if l < len(A) and A[l-1] > A[i-1]:
        largest = l
    else:
        largest = i
    if r < len(A) and A[r-1] > A[largest-1]:
        largest = r

    if largest != i:
        temp = A[i-1]
        A[i-1] = A[largest-1]
        A[largest-1] = temp
        print largest
        return max_heapify(A, largest)

    return A

def min_heapify(A, i):
    l = left(i)
    r = right(i)

    print 'Root: %s' % i
    print 'Left: %s' % l
    print 'Right: %s' % r

    if l <= len(A) and A[l-1] < A[i-1]:
        smallest = l
    else:
        smallest = i
    if r <= len(A) and A[r-1] < A[smallest-1]:
        smallest = r

    print 'Smallest: %s' % smallest
    if smallest != i:
        temp = A[i-1]
        A[i-1] = A[smallest-1]
        A[smallest-1] = temp
        print A
        return min_heapify(A, smallest)

    return A

# min_heapify, compared to max_heapify - the run both at time O(lg n)

# Calling max_heapify when the element A[i] is larger than its children
# will make the procedure stop and return at that point. Since this is the
# the return point of the recursive procedure.