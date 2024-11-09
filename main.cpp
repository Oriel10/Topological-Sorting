#include "DAG.hpp"
#include "vector"

int main() {
    DAG graph;

    // Add nodes
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);

    // Add edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(7, 6);

    // Display the graph
    vector<int> topoSort = graph.topologicalSort();
    for(const auto& elem : topoSort) {
      std::cout << elem << " ";
    }
    return 0;
}
