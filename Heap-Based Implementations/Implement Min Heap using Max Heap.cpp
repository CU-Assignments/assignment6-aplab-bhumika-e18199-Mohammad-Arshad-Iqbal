#include <iostream>
#include <queue>
using namespace std;

class MinHeap {
    priority_queue<int> maxHeap; // Max Heap

public:
    void push(int val) {
        maxHeap.push(-val); // Store negative values
    }

    void pop() {
        maxHeap.pop();
    }

    int top() {
        return -maxHeap.top(); // Convert back to positive
    }

    bool empty() {
        return maxHeap.empty();
    }
};

int main() {
    MinHeap mh;
    mh.push(10);
    mh.push(20);
    mh.push(5);

    cout << "Min Heap using Max Heap: ";
    while (!mh.empty()) {
        cout << mh.top() << " ";
        mh.pop();
    }
    // Output: 5 10 20
    return 0;
}
