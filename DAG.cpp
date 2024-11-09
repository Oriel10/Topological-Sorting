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
  // std::cout << "inDegreeZero:\n";
  // while (!inDegreeZero.empty()) {
  //   std::cout << inDegreeZero.front()->id << " ";
  //   inDegreeZero.pop();
  // }
  while(!inDegreeZero.empty()) {
    DAGNode* curr = inDegreeZero.front();
    // std::cout << "inDegreeZero.size(): " << inDegreeZero.size()<<std::endl;
    // std::cout << "curr: " << curr->id<<std::endl;
    
    inDegreeZero.pop();
    topologicalOrder.push_back(curr->id);

    // std::cout << "outgoing: " <<std::endl;
    for(DAGNode* neighbor : curr->outgoing) {
      // std::cout << neighbor->id <<" " << std::endl;

      inDegreeCopy[neighbor->id]--;
      if(inDegreeCopy[neighbor->id] == 0) {
        inDegreeZero.push(neighbor);
      }
    }
  }
  // std::cout << "topologicalOrder:\n";
  // for(const auto& elem : topologicalOrder) {
    // std::cout << elem << " ";
  // }
  // std::cout << std::endl;
  if (topologicalOrder.size() != nodes.size()) {
      std::cerr << "The graph contains a cycle! Topological sort not possible.\n";
      return {};
  }

  
  return topologicalOrder;
};