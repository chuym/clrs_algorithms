def merge_lists(lists):
    heap = MinHeap([])
    def insert_in_heap(heap, item):
        heap.insert(item)
        return heap

    def insert_list_in_heap(heap, l):
        return reduce(insert_in_heap, l, heap)

    return reduce(insert_list_in_heap, lists, heap)