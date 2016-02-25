class Heap(object):
    def __init__(self, elements, **kwargs):
        self.arity = 2
        if 'arity' in kwargs:
            self.arity = kwargs['arity']

        self.elements = list(elements)
        self.heap_size = len(elements)
        self.length = len(elements)


    def elements_length(self):
        return self.length

    def swap(self, a, b):
        temp = self[a]
        self[a] = self[b]
        self[b] = temp

    def parent(self, i):
        return int(ceil((i - 1) / float(self.arity)))

    def children(self, i):
        first = ((i - 1) * self.arity) + 2
        return [ first + k for k in range(self.arity) ]

    def __getitem__(self, key):
        return self.elements[key-1]

    def __setitem__(self, key, value):
        self.elements[key-1] = value

    def __len__(self):
        return self.heap_size

    def __str__(self):
        return str(self.elements)
