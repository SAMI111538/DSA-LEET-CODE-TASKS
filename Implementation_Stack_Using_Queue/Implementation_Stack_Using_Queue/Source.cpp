#include <iostream>
#include <stack>
#include <queue>
#include <stdexcept> // Include the <stdexcept> header for exceptions
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    void Push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is already empty" << endl;
            return -1; // Return a sentinel value to indicate the error
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int top_value = s2.top();
        s2.pop();
        return top_value;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);

    cout << q.pop() << endl;
    q.Push(6);
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}


