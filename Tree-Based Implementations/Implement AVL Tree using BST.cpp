#include <iostream>
using namespace std;

class Node {
public:
    int data, height;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        node->height = max(height(node->left), height(node->right)) + 1;
        int bf = balanceFactor(node);

        // Left Heavy
        if (bf > 1 && val < node->left->data) return rotateRight(node);
        // Right Heavy
        if (bf < -1 && val > node->right->data) return rotateLeft(node);
        // Left Right Case
        if (bf > 1 && val > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // Right Left Case
        if (bf < -1 && val < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

// Driver Code
int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder Traversal of AVL Tree: ";
    tree.inorder(); // Output: 10 20 25 30 40 50
    return 0;
}
