#include <stack>
#include <iostream>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;  // Stores all elements
    stack<int> minStack;   // Stores minimum values

public:
    MinStack() {}

    // Push an element
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x); // Update minStack if x is the new minimum
        }
    }

    // Remove top element
    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == minStack.top()) {
            minStack.pop();  // Remove from minStack if it was the min element
        }
        mainStack.pop();
    }

    // Get the top element
    int top() {
        return mainStack.top();
    }

    // Get the minimum element
    int getMin() {
        return minStack.top();
    }
};

// Example usage
int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(5);
    cout << "Min: " << minStack.getMin() << endl; // 3
    minStack.push(2);
    minStack.push(1);
    cout << "Min: " << minStack.getMin() << endl; // 1
    minStack.pop();
    cout << "Min after pop: " << minStack.getMin() << endl; // 2
    return 0;
}
