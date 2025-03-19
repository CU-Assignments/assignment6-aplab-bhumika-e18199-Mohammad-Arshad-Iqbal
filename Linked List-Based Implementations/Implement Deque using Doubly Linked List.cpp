#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class MyDeque {
private:
    Node* front;
    Node* rear;
    int size;

public:
    MyDeque() {
        front = rear = nullptr;
        size = 0;
    }

    void pushFront(int x) {
        Node* newNode = new Node(x);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void pushBack(int x) {
        Node* newNode = new Node(x);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }

    int popFront() {
        if (!front) return -1;
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
        size--;
        return val;
    }

    int popBack() {
        if (!rear) return -1;
        int val = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
        size--;
        return val;
    }

    int getFront() {
        return front ? front->data : -1;
    }

    int getBack() {
        return rear ? rear->data : -1;
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    MyDeque deque;
    deque.pushFront(1);
    deque.pushBack(2);
    deque.pushFront(3);
    cout << "Front: " << deque.getFront() << endl; // 3
    cout << "Back: " << deque.getBack() << endl;   // 2
    cout << "Pop Front: " << deque.popFront() << endl; // 3
    cout << "Pop Back: " << deque.popBack() << endl;   // 2
    cout << "Empty: " << deque.empty() << endl; // 0 (false)
    return 0;
}
