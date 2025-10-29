class MyStack {
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int n = q.size();
        while (n-- > 1) {
            q.push(q.front());
            q.pop();
        }
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};
