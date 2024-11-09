#include "DAG.hpp"
#include <queue>

DAG::~DAG() {
  for(auto node_pair : nodes) {
    delete node_pair.second;
  }
}

void DAG::addNode(int id) {
  if(nodes.find(id) == nodes.end()) {
    nodes[id] = new DAGNode(id);    
  }
}

void DAG::addEdge(int fromId, int toId) {
  if (nodes.find(fromId) == nodes.end() || nodes.find(toId) == nodes.end()) {
    std::cout << "One or both nodes not found!\n";
    return;
  }
  nodes[fromId]->addEdge(nodes[toId]);
}


void DAG::display() const {
  for (const auto& pair : nodes) {
      pair.second->displayConnections();
  }
}

// Topological sort using Kahn's Algorithm
std::vector<int> DAG::topologicalSort() {
  std::vector<int> topologicalOrder;
  std::queue<DAGNode*> inDegreeZero;
  std::unordered_map<int, int> inDegreeCopy;

  for(const auto& node_pair : nodes) {
    inDegreeCopy[node_pair.first] = node_pair.second->inDegree; 
    if(node_pair.second->inDegree == 0) {
      inDegreeZero.push(node_pair.second);
    }
  }
  while(!inDegreeZero.empty()) {
    DAGNode* curr = inDegreeZero.front();
    inDegreeZero.pop();
    topologicalOrder.push_back(curr->id);

    for(DAGNode* neighbor : curr->outgoing) {
      inDegreeCopy[neighbor->id]--;
      if(inDegreeCopy[neighbor->id] == 0) {
        inDegreeZero.push(neighbor);
      }
    }
  }
  
  if (topologicalOrder.size() != nodes.size()) {
      std::cerr << "The graph contains a cycle! Topological sort not possible.\n";
      return {};
  }

  return topologicalOrder;
};