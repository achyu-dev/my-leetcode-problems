#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    MyStack() {}

    queue<int> q;

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl; // returns 2
    cout << obj->pop() << endl; // returns 2
    cout << obj->empty() << endl; // returns false
    return 0;
}
