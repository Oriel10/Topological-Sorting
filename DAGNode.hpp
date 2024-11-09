#ifndef NODE_HPP
#define NODE_HPP

#include <unordered_set>
#include <iostream>

class DAGNode {
public:
    int id;                              // Unique identifier for the node
    std::unordered_set<DAGNode*> outgoing;         // List of nodes this node points to
    int inDegree;                        // Number of incoming edges
    int outDegree;                       // Number of outgoing edges

    // Constructor
    DAGNode(int nodeId);

    // Add an edge from this node to another node
    void addEdge(DAGNode* target);

    // Remove an edge from the outgoing of this node
    bool removeEdge(DAGNode* target);

    // Display connections and degree information
    void displayConnections() const;
};

#endif  // NODE_HPP
