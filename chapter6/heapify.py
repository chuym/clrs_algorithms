class Heap(object):
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
