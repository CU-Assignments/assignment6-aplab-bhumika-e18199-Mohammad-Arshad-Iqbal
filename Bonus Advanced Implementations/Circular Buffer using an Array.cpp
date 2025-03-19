#include <iostream>
using namespace std;

class CircularBuffer {
    int *buffer;
    int front, rear, size, capacity;

public:
    CircularBuffer(int cap) {
        capacity = cap;
        buffer = new int[cap];
        front = rear = -1;
        size = 0;
    }

    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Buffer Full\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        buffer[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Buffer Empty\n";
            return -1;
        }
        int val = buffer[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    void display() {
        if (isEmpty()) {
            cout << "Buffer Empty\n";
            return;
        }
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << buffer[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~CircularBuffer() { delete[] buffer; }
};

// Driver Code
int main() {
    CircularBuffer cb(3);
    cb.enqueue(10);
    cb.enqueue(20);
    cb.enqueue(30);
    cb.display();
    cb.dequeue();
    cb.enqueue(40);
    cb.display();
    return 0;
}
