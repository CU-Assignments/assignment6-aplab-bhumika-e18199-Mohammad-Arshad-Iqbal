#include <iostream>
#include <queue>
using namespace std;

class MaxHeap {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min Heap

public:
    void push(int val) {
        minHeap.push(val);
    }

    void pop() {
        minHeap.pop();
    }

    int top() {
        return minHeap.top();
    }

    bool empty() {
        return minHeap.empty();
    }
};

int main() {
    MaxHeap mh;
    mh.push(10);
    mh.push(20);
    mh.push(5);

    cout << "Max Heap using Min Heap: ";
    while (!mh.empty()) {
        cout << mh.top() << " ";
        mh.pop();
    }
    // Output: 5 10 20 (Incorrect order for Max Heap)

    return 0;
}
