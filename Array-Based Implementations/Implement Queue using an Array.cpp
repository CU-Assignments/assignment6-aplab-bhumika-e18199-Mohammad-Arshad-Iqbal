#include <iostream>
using namespace std;

class MyStack {
private:
    int *arr;
    int topIndex, capacity;

public:
    MyStack(int cap = 1000) {
        capacity = cap;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++topIndex] = x;
    }

    int pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top() {
        if (topIndex == -1) return -1;
        return arr[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }

    ~MyStack() {
        delete[] arr;
    }
};

int main() {
    MyStack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top: " << stack.top() << endl; // 3
    cout << "Pop: " << stack.pop() << endl; // 3
    cout << "Top after pop: " << stack.top() << endl; // 2
    cout << "Empty: " << stack.empty() << endl; // 0 (false)
    return 0;
}
