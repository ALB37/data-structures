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
        if (startCoordinates not in self._adjacencies
                or endCoordinates not in self._adjacencies):
            raise ValueError('start or end coordinates do not exist')

        adjacentList = self._adjacencies[startCoordinates]

        adjacentList.append({
            'node' : endCoordinates,
            'weight' : weight,
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

    def dijkstraSearch(self, startCoordinates, endCoordinates):
        visitedNodes = set()
        parentMap = {}
        shortestPath = {}
        openList = PriorityQueue()

        openList.put((0, startCoordinates))

        shortestPath[startCoordinates] = 0

        while not openList.empty():
            currentNode = openList.get()[1]

            if currentNode in visitedNodes:
                continue

            visitedNodes.add(currentNode)

            if currentNode == endCoordinates:
                return parentMap

            neighbors = self.getNeighbors(currentNode)

            for neighbor in neighbors:
                node = neighbor['node']
                weight = neighbor['weight']

                if node in visitedNodes:
                    continue

                newPathWeight = shortestPath[currentNode] + weight

                if (node not in shortestPath
                        or newPathWeight < shortestPath[node]):
                    shortestPath[node] = newPathWeight
                    parentMap[node] = currentNode

                    openList.put((shortestPath[node], node))

        return None

    @staticmethod
    def calculateDist(startCoordinates, endCoordinates):
        # This method assumes x, y coordinate numbers as a tuple
        if (not isinstance(startCoordinates, tuple)
                or not isinstance(endCoordinates, tuple)):
            raise TypeError('arguments must be tuples')
        
        if len(startCoordinates) != 2 or len(endCoordinates) != 2:
            raise IndexError('arguments must be of length 2')

        startNum = startCoordinates[0] + startCoordinates[1]
        endNum = endCoordinates[0] + endCoordinates[1]

        return abs(endNum - startNum)

    # Assumes an x, y coordinate grid address system
    def aStarSearch(self, startCoordinates, endCoordinates):
        visitedNodes = set()
        parentMap = {}
        fastestPath = {}
        shortestPath = {}
        openList = PriorityQueue()

        openList.put((0, startCoordinates))

        fastestPath[startCoordinates] = 0
        shortestPath[startCoordinates] = self.calculateDist(startCoordinates,
                                                            endCoordinates)

        while not openList.empty():
            currentNode = openList.get()[1]

            if currentNode in visitedNodes:
                continue

            visitedNodes.add(currentNode)

            if currentNode == endCoordinates:
                return parentMap

            neighbors = self.getNeighbors(currentNode)

            for neighbor in neighbors:
                node = neighbor['node']
                weight = neighbor['weight']

                if node in visitedNodes:
                    continue

                newPathWeight = fastestPath[currentNode] + weight

                if (node not in fastestPath
                        or newPathWeight < fastestPath[node]):
                    parentMap[node] = currentNode
                    fastestPath[node] = newPathWeight
                    shortestPath[node] = (fastestPath[node] 
                        + self.calculateDist(node, endCoordinates))

                    openList.put((shortestPath[node], node))

        return None

    @staticmethod
    def outputPath(pathMap, startCoordinates, endCoordinates):
        fastestPath = deque()
        currentCoordinates = endCoordinates
        fastestPath.appendleft(currentCoordinates)

        while currentCoordinates != startCoordinates:
            fastestPath.appendleft(pathMap[currentCoordinates])
            currentCoordinates = pathMap[currentCoordinates]
        
        return fastestPath


# from graph import Graph
# g = Graph()
# node1 = {'xy': (0, 0), 'weight': 3}
# node2 = {'xy': (0, 1), 'weight': 4}
# node3 = {'xy': (0, 2), 'weight': 9}
# node4 = {'xy': (1, 0), 'weight': 9}
# node5 = {'xy': (1, 1), 'weight': 3}
# node6 = {'xy': (1, 2), 'weight': 9}
# node7 = {'xy': (2, 0), 'weight': 9}
# node8 = {'xy': (2, 1), 'weight': 1}
# node9 = {'xy': (2, 2), 'weight': 3}
# g.addNode(node1['xy'])
# g.addNode(node2['xy'])
# g.addNode(node3['xy'])
# g.addNode(node4['xy'])
# g.addNode(node5['xy'])
# g.addNode(node6['xy'])
# g.addNode(node7['xy'])
# g.addNode(node8['xy'])
# g.addNode(node9['xy'])
# g.addEdge(node1['xy'], node2['xy'], node2['weight'])
# g.addEdge(node1['xy'], node4['xy'], node4['weight'])
# g.addEdge(node2['xy'], node3['xy'], node3['weight'])
# g.addEdge(node2['xy'], node5['xy'], node5['weight'])
# g.addEdge(node3['xy'], node6['xy'], node6['weight'])
# g.addEdge(node4['xy'], node1['xy'], node1['weight'])
# g.addEdge(node4['xy'], node5['xy'], node5['weight'])
# g.addEdge(node4['xy'], node7['xy'], node7['weight'])
# g.addEdge(node5['xy'], node2['xy'], node2['weight'])
# g.addEdge(node5['xy'], node4['xy'], node4['weight'])
# g.addEdge(node5['xy'], node6['xy'], node6['weight'])
# g.addEdge(node5['xy'], node8['xy'], node8['weight'])
# g.addEdge(node6['xy'], node3['xy'], node3['weight'])
# g.addEdge(node6['xy'], node5['xy'], node5['weight'])
# g.addEdge(node6['xy'], node9['xy'], node9['weight'])
# g.addEdge(node7['xy'], node4['xy'], node4['weight'])
# g.addEdge(node7['xy'], node8['xy'], node8['weight'])
# g.addEdge(node8['xy'], node7['xy'], node7['weight'])
# g.addEdge(node8['xy'], node5['xy'], node5['weight'])
# g.addEdge(node8['xy'], node9['xy'], node9['weight'])
# g.aStarSearch(node1['xy'], node9['xy'])
