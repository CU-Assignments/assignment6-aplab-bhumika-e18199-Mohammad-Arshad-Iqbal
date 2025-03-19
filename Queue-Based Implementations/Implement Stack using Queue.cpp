#include <queue>
#include <iostream>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    // Push element onto stack
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size-- > 1) {  // Rotate the queue to maintain LIFO order
            q.push(q.front());
            q.pop();
        }
    }

    // Removes and returns the top element
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    // Get the top element
    int top() {
        return q.front();
    }

    // Returns whether the stack is empty
    bool empty() {
        return q.empty();
    }
};

// Example usage
int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top: " << stack.top() << endl;  // 3
    cout << "Pop: " << stack.pop() << endl;  // 3
    cout << "Top after pop: " << stack.top() << endl; // 2
    return 0;
}
