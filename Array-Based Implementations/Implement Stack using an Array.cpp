#include <iostream>
using namespace std;

class MyQueue {
private:
    int *arr;
    int frontIndex, rearIndex, capacity, size;

public:
    MyQueue(int cap = 1000) {
        capacity = cap;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    void enqueue(int x) {
        if (size == capacity) {
            cout << "Queue is full!\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int frontElement = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return frontElement;
    }

    int front() {
        if (size == 0) return -1;
        return arr[frontIndex];
    }

    bool empty() {
        return size == 0;
    }

    ~MyQueue() {
        delete[] arr;
    }
};

int main() {
    MyQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front: " << q.front() << endl; // 1
    cout << "Dequeue: " << q.dequeue() << endl; // 1
    cout << "Front after dequeue: " << q.front() << endl; // 2
    cout << "Empty: " << q.empty() << endl; // 0 (false)
    return 0;
}
