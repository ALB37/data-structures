class MinHeap:
    def __init__(self):
        self._data = []

    def peek(self):
        if not self._data:
            return
        else:
            return self._data[0]
    
    def insert(self, value):
        if type(value) not in [int, float]:
            raise TypeError("Min Heap can only take numbers as values")

        self._data.append(value)
        self._bubbleUp(len(self._data) - 1)

    def _bubbleUp(self, index):
        if index == 0:
            return
        
        parent = self._parentIndex(index)

        if self._data[parent] > self._data[index]:
            self._swap(parent, index)
            self._bubbleUp(parent)
    
    @staticmethod
    def _parentIndex(index):
        return (index - 1) // 2

    def _swap(self, i, j):
        temp = self._data[i]

        self._data[i] = self._data[j]
        self._data[j] = temp

    def extractMin(self):
        if not self._data:
            return

        min_val = self._data[0]
        last_val = self._data.pop()

        if self._data:
            self._data[0] = last_val
            self._bubbleDown(0)

        return min_val

    @staticmethod
    def _leftChildIndex(index):
        return (2 * index) + 1

    @staticmethod
    def _rightChildIndex(index):
        return (2 * index) + 2

    def _bubbleDown(self, index):
        min_index = index
        leftIndex = self._leftChildIndex(index)
        rightIndex = self._rightChildIndex(index)

        if leftIndex <= len(self._data) - 1:
            if self._data[min_index] > self._data[leftIndex]:
                min_index = leftIndex
        
        if rightIndex <= len(self._data) - 1:
            if self._data[min_index] > self._data[rightIndex]:
                min_index = rightIndex

        if min_index != index:
            self._swap(index, min_index)
            self._bubbleDown(min_index)
        
