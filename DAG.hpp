#ifndef DAG_HPP
#define DAG_HPP

#include "DAGNode.hpp"
#include <unordered_map>
#include <vector>

class DAG {
private:
    std::unordered_map<int, DAGNode*> nodes;  // Map from node ID to Node pointer

public:
    // Destructor
    ~DAG();

    // Add a new node to the graph
    void addNode(int id);

    // Add a directed edge between two nodes
    void addEdge(int fromId, int toId);

    // Display the entire graph
    void display() const;

    // Topological sort using Kahn's Algorithm
    std::vector<int> topologicalSort();
};

#endif  // DAG_HPP
