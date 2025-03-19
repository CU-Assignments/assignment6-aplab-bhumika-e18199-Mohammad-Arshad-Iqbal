#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
    unordered_map<int, list<int>> adjList;

public:
    void addEdge(int u, int v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) adjList[v].push_back(u);
    }

    void printGraph() {
        for (auto node : adjList) {
            cout << node.first << " -> ";
            for (auto neighbor : node.second)
                cout << neighbor << " ";
            cout << endl;
        }
    }
};

// Driver Code
int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency List Representation:\n";
    g.printGraph();
    return 0;
}
