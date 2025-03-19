#include <stack>
#include <iostream>
using namespace std;

class DequeUsingStacks {
private:
    stack<int> frontStack, backStack;

    void transfer(stack<int>& from, stack<int>& to) {
        while (!from.empty()) {
            to.push(from.top());
            from.pop();
        }
    }

public:
    // Insert element at the front
    void pushFront(int x) {
        frontStack.push(x);
    }

    // Insert element at the back
    void pushBack(int x) {
        backStack.push(x);
    }

    // Remove and return front element
    int popFront() {
        if (frontStack.empty()) {
            if (backStack.empty()) throw runtime_error("Deque is empty!");
            transfer(backStack, frontStack);
        }
        int topElement = frontStack.top();
        frontStack.pop();
        return topElement;
    }

    // Remove and return back element
    int popBack() {
        if (backStack.empty()) {
            if (frontStack.empty()) throw runtime_error("Deque is empty!");
            transfer(frontStack, backStack);
        }
        int topElement = backStack.top();
        backStack.pop();
        return topElement;
    }

    // Get the front element
    int front() {
        if (frontStack.empty()) {
            if (backStack.empty()) throw runtime_error("Deque is empty!");
            transfer(backStack, frontStack);
        }
        return frontStack.top();
    }

    // Get the back element
    int back() {
        if (backStack.empty()) {
            if (frontStack.empty()) throw runtime_error("Deque is empty!");
            transfer(frontStack, backStack);
        }
        return backStack.top();
    }

    // Check if deque is empty
    bool empty() {
        return frontStack.empty() && backStack.empty();
    }
};

// Example usage
int main() {
    DequeUsingStacks dq;
    dq.pushFront(1);
    dq.pushBack(2);
    dq.pushFront(3);
    cout << "Front: " << dq.front() << endl;  // 3
    cout << "Back: " << dq.back() << endl;    // 2
    dq.popFront();
    cout << "Front after popFront: " << dq.front() << endl;  // 1
    dq.popBack();
    cout << "Back after popBack: " << dq.back() << endl;      // 1
    return 0;
}
