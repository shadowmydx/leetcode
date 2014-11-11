class MinStack {
private:
    stack<int> trueStk;
    stack<int> minStk;
public:
    void push(int x) {
        trueStk.push(x);
        if (minStk.size() == 0)
            minStk.push(x);
        else
        {
            int tmp = getMin();
            if (x <= tmp)
                minStk.push(x);
        }
    }

    void pop() {
        int tmp = top();
        trueStk.pop();
        if (tmp == getMin())
            minStk.pop();
    }

    int top() {
        return trueStk.top();
    }

    int getMin() {
        return minStk.top();
    }
};