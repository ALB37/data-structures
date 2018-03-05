'use strict';

module.exports = (graph, startNode, targetNode) => {
  const queue = [];
  const visitedNodes = new Set();
  const parentMap = new Map();

  queue.unshift(startNode);
  visitedNodes.add(startNode);

  while (queue.length){
    let currentNode = queue.pop();
    if (currentNode === targetNode){
      return parentMap;
    }
    let neighbors = graph.getNeighbors(currentNode);
    for (let neighbor of neighbors){
      let neighborNode = neighbor.node;

      if (visitedNodes.has(neighborNode)){
        continue;
      }
      visitedNodes.add(neighborNode);
      parentMap.set(neighborNode, currentNode);
      queue.unshift(neighborNode);
    }
  }

  return null;
};