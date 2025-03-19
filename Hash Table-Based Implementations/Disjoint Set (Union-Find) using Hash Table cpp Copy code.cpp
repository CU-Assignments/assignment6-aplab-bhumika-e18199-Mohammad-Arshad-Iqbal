#include <iostream>
#include <unordered_map>
using namespace std;

class DisjointSet {
    unordered_map<int, int> parent, rank;

public:
    void makeSet(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    int findSet(int v) {
        if (parent[v] != v)
            parent[v] = findSet(parent[v]); // Path compression
        return parent[v];
    }

    void unionSets(int a, int b) {
        int rootA = findSet(a);
        int rootB = findSet(b);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB])
                parent[rootA] = rootB;
            else if (rank[rootA] > rank[rootB])
                parent[rootB] = rootA;
            else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }

    void printSets() {
        for (auto& p : parent)
            cout << "Element: " << p.first << ", Set: " << findSet(p.first) << endl;
    }
};

// Driver Code
int main() {
    DisjointSet ds;
    ds.makeSet(1);
    ds.makeSet(2);
    ds.makeSet(3);
    ds.makeSet(4);
    ds.makeSet(5);

    ds.unionSets(1, 2);
    ds.unionSets(3, 4);
    ds.unionSets(2, 3);

    cout << "Disjoint Sets:\n";
    ds.printSets();
    return 0;
}
