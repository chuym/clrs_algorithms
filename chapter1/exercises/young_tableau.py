class Tableau(object):
    def __init__(self, row_size, column_size):
        self.tableau = [MaxHeap([])]
        self.current = 0
        self.row_size = row_size
        self.column_size = column_size

    def insert(self, i):
        heap = self._find_heap_for(i)
        if heap.heap_size >= self.row_size:
            temp = heap.extract_max()
            heap.insert(i)
            self.insert(temp)
        else:
            heap.insert(i)

    def _find_heap_for(self, i):
        heap = None
        for h in self.tableau:
            if h.heap_size < self.row_size:
                heap = h
                break
            if i < h.maximum():
                heap = h
                break

        if heap is None:
            heap = self._add_heap()

        return heap

    def _add_heap(self):
        if len(self.tableau) >= self.column_size:
            raise 'Tableau overflow'

        heap = MaxHeap([])
        self.tableau.append(heap)
        return heap

    def __str__(self):
        raw = map(lambda h : heapsort(h.elements), self.tableau)
        return str(raw)