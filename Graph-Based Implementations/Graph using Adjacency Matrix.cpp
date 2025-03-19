#include <iostream>
using namespace std;

class Graph {
    int **adjMatrix;
    int size;

public:
    Graph(int n) {
        size = n;
        adjMatrix = new int*[n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n];
            for (int j = 0; j < n; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void addEdge(int u, int v, bool bidir = true) {
        adjMatrix[u][v] = 1;
        if (bidir) adjMatrix[v][u] = 1;
    }

    void printGraph() {
        cout << "Adjacency Matrix Representation:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < size; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

// Driver Code
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    return 0;
}
