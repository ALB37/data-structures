class Graph:
    def __init__(self):
        self._adjacencies = {}

    def addNode(self, coordinates):
        # coordinates will be a tuple of the form (x, y)
        self._adjacencies[coordinates] = []

    def addEdge(self, startCoordinates, endCoordinates, weight=0):
        if startCoordinates not in self._adjacencies \
                or endCoordinates not in self._adjacencies:
            raise ValueError('start or end coordinates do not exist')

        adjacentList = self._adjacencies[startCoordinates]

        adjacentList.append({
            'node' : endCoordinates,
            'weight' : weight
        })

    def getNeighbors(self, coordinates):
        if coordinates not in self._adjacencies:
            raise ValueError('coordinates not in graph')

        return self._adjacencies[coordinates][:]

