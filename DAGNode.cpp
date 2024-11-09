#include "DAGNode.hpp"

DAGNode::DAGNode(int nodeId) : id(nodeId), inDegree(0), outDegree(0) {}

void DAGNode::addEdge(DAGNode* target) {
  auto result = outgoing.insert(target);  // Insert directly
  if (result.second) {                    // Check if insertion succeeded
      outDegree++;
      target->inDegree++;
  }
}

// Remove an edge from this node to the target node
bool DAGNode::removeEdge(DAGNode* target) {
    if (outgoing.erase(target)) {  // Erase returns 1 if the element was found and removed
        outDegree--;
        target->inDegree--;
        return true;
    }
    return false;  // Edge not found
}

void DAGNode::displayConnections() const {
    std::cout << "Node " << id << " -> ";
    for (const auto& node : outgoing) {
        std::cout << node->id << " ";
    }
    std::cout << "\nIn-degree: " << inDegree << ", Out-degree: " << outDegree << "\n";
}