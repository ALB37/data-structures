'use strict';

const PriorityQueue = require('js-priority-queue');

module.exports = (graph, startNode, targetNode) => {
  const visitedNodes = new Set();
  const parentMap = new Map();
  const shortestPathSoFar = new Map();
  
  const priorityQueue = new PriorityQueue({
    comparator: (a, b) => a.priority - b.priority,
  });

  priorityQueue.queue({
    node: startNode,
    priority: 0,
  });

  shortestPathSoFar.set(startNode, 0);

  while (priorityQueue.length){
    const currentNode = priorityQueue.dequeue().node;

    if (visitedNodes.has(currentNode)){
      continue;
    }

    visitedNodes.add(currentNode);

    if (currentNode === targetNode){
      return parentMap;
    }

    const neighbors = graph.getNeighbors(currentNode);

    for (let neighbor of neighbors){
      const {weight, node} = neighbor;

      if (visitedNodes.has(node)){
        continue;
      }

      const newPathWeight = shortestPathSoFar.get(currentNode) + weight;

      if (!shortestPathSoFar.has(neighbor) || newPathWeight < shortestPathSoFar.get(node)){
        shortestPathSoFar.set(node, newPathWeight);
        parentMap.set(node, currentNode);

        priorityQueue.queue({
          node,
          priority: shortestPathSoFar.get(node),
        });
      }
    }

  }
};