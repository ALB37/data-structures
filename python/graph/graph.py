class Graph:
    def __init__(self):
        self._adjacencies = {}

    def addNode(self, nodeCoordinates):
        # node will be a tuple of the form (x, y)
        self._adjacencies[nodeCoordinates] = []

    def addEdge(self, startNode, endNode, weight=0):
        if startNode not in self._adjacencies \
                or endNode not in self._adjacencies:
            raise ValueError('startNode or endNode does not exist')

    





            
