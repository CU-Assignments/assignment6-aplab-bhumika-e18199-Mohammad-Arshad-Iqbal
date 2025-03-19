#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class LFUCache {
    int capacity, minFreq;
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };
    unordered_map<int, Node*> cache;
    unordered_map<int, set<Node*>> freqList;

public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        freqList[node->freq].erase(node);
        if (freqList[node->freq].empty() && node->freq == minFreq) minFreq++;
        node->freq++;
        freqList[node->freq].insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            get(key);
            return;
        }

        if (cache.size() == capacity) {
            Node* node = *freqList[minFreq].begin();
            cache.erase(node->key);
            freqList[minFreq].erase(node);
            delete node;
        }

        Node* newNode = new Node(key, value, 1);
        cache[key] = newNode;
        freqList[1].insert(newNode);
        minFreq = 1;
    }
};

// Driver Code
int main() {
    LFUCache lfu(2);
    lfu.put(1, 10);
    lfu.put(2, 20);
    cout << "Get(1): " << lfu.get(1) << endl; // 10
    lfu.put(3, 30); // Evicts least frequently used key 2
    cout << "Get(2): " << lfu.get(2) << endl; // -1 (not found)
    return 0;
}
