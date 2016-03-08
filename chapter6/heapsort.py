def heapsort(A):
    heap = MaxHeap(A)
    for i in xrange(heap.elements_length(), 1, -1):
        heap.swap(1, i)
        heap.heap_size = heap.heap_size - 1
        max_heapify(heap, 1)

    return heap.elements

# Invariant: At the beginning of the loop: A[1..i] is a
# max_heap, while the elements from A[i+1..n] contain the largest
# elements of A[1..n] sorted
#
# At the beginning, we build a max heap, and the subarra A[i+1..n]
# is empty, so the invariant holds
#
# On the first iteration, we begin with a max heap where A[1] is the
# largest element and i = n, when we exchange A[1] with A[i], we end
# having the largest element at A[i], which is A[n]. We decrement
# the heap size, excluding the last element (which is the largest)
# and build a max heap with the reamining elements. At the end
# of the first iteration we have a max heap with A[1..i-1] and the
# subarray A[i..n] is sorted