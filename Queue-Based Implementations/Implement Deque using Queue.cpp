#include <queue>
#include <iostream>
using namespace std;

class MyDeque {
private:
    queue<int> q1, q2;

public:
    MyDeque() {}

    void pushFront(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pushBack(int x) {
        q1.push(x);
    }

    int popFront() {
        if (q1.empty()) return -1;
        int frontElement = q1.front();
        q1.pop();
        return frontElement;
    }

    int popBack() {
        if (q1.empty()) return -1;
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int backElement = q1.front();
        q1.pop();
        swap(q1, q2);
        return backElement;
    }

    int front() {
        return q1.empty() ? -1 : q1.front();
    }

    int back() {
        if (q1.empty()) return -1;
        queue<int> temp = q1;
        while (temp.size() > 1) {
            temp.pop();
        }
        return temp.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyDeque deque;
    deque.pushFront(1);
    deque.pushBack(2);
    deque.pushFront(3);
    cout << "Front: " << deque.front() << endl; // 3
    cout << "Back: " << deque.back() << endl;   // 2
    cout << "Pop Front: " << deque.popFront() << endl; // 3
    cout << "Pop Back: " << deque.popBack() << endl;   // 2
    cout << "Empty: " << deque.empty() << endl; // 0 (false)
    return 0;
}
