#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() {
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) return false;
            node = node->children[ch];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) return false;
            node = node->children[ch];
        }
        return true;
    }
};

// Driver Code
int main() {
    Trie trie;
    trie.insert("apple");
    cout << "Search 'apple': " << trie.search("apple") << endl;   // 1 (true)
    cout << "Search 'app': " << trie.search("app") << endl;       // 0 (false)
    cout << "Starts with 'app': " << trie.startsWith("app") << endl; // 1 (true)
    trie.insert("app");
    cout << "Search 'app' after inserting: " << trie.search("app") << endl; // 1 (true)
    return 0;
}
