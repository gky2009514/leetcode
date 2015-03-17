class MinStack {
public:
    MinStack() {
        while (!data.empty())
            data.pop();
        while (!minall.empty())
            minall.pop();
    }
    
    void push(int x) {
        data.push(x);
        if (minall.empty())
            minall.push(x);
        else {
            int top = minall.top();
            if (x <= top)
                minall.push(x);
        }
    }
    
    void pop() {
        if (!data.empty()) {
            int top = data.top();
            data.pop();
            if (top == minall.top())
                minall.pop();
        }
    }
    
    int top() {
        if (!data.empty())
            return data.top();
        return -1;
    }
    
    int getMin() {
        if (!minall.empty())
            return minall.top();
        return -1;
    }
private:
    stack<int> data, minall;
};