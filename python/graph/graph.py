from collections import deque
from queue import PriorityQueue

class Graph:
    def __init__(self):
        self._adjacencies = {}

    def addNode(self, coordinates):
        # coordinates can be any immutable data type,
        # potentially a tuple of the form (x, y), for instance
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

        neighborList = self._adjacencies[coordinates]

        return [dict(neighbor) for neighbor in neighborList]

    def breadthFirst(self, startCoordinates, endCoordinates):
        queue = deque()
        visitedNodes = set()
        parentMap = {}

        queue.append(startCoordinates)
        visitedNodes.add(startCoordinates)

        while queue:
            currentNode = queue.popleft()
            if currentNode == endCoordinates:
                return parentMap
            
            neighbors = self.getNeighbors(currentNode)

            for neighbor in neighbors:
                neighborNode = neighbor['node']

                if neighborNode in visitedNodes:
                    continue

                visitedNodes.add(neighborNode)
                parentMap[neighborNode] = currentNode
                queue.append(neighborNode)

        return None

    def depthFirst(self, startCoordinates, endCoordinates):
        stack = []
        visitedNodes = set()
        parentMap = {}

        stack.append(startCoordinates)
        visitedNodes.add(startCoordinates)

        while stack:
            currentNode = stack.pop()
            if currentNode == endCoordinates:
                return parentMap
            
            neighbors = self.getNeighbors(currentNode)

            for neighbor in neighbors:
                neighborNode = neighbor['node']

                if neighborNode in visitedNodes:
                    continue

                visitedNodes.add(neighborNode)
                parentMap[neighborNode] = currentNode
                stack.append(neighborNode)

        return None





