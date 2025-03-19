#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class MyStack {
private:
    Node* topNode;

public:
    MyStack() {
        topNode = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (!topNode) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int val = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return val;
    }

    int top() {
        return topNode ? topNode->data : -1;
    }

    bool empty() {
        return topNode == nullptr;
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top: " << stack.top() << endl; // 3
    cout << "Pop: " << stack.pop() << endl; // 3
    cout << "Top after pop: " << stack.top() << endl; // 2
    cout << "Empty: " << stack.empty() << endl; // 0 (false)
    return 0;
}
