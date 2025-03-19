#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq; // Max Heap

    pq.push(10);
    pq.push(20);
    pq.push(15);

    cout << "Priority Queue (Max Heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    // Output: 20 15 10
    return 0;
}
