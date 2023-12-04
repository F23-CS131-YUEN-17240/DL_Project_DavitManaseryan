#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void DFS(int startVertex);

private:
    int vertices;
    vector<vector<int>> adjacencyList;
    void DFSUtil(int vertex, vector<bool>& visited);
};

Graph::Graph(int vertices) : vertices(vertices), adjacencyList(vertices) {}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v);  // Assuming an undirected graph
}

void Graph::DFSUtil(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : adjacencyList[vertex]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}

void Graph::DFS(int startVertex) {
    vector<bool> visited(vertices, false);
    DFSUtil(startVertex, visited);
}

int main() {
    // Example usage
    Graph graph(6);  // Assuming 6 vertices in the graph

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);

    cout << "DFS starting from vertex 0: ";
    graph.DFS(0);

    return 0;
}
