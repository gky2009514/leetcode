class Stack {
public:
    Stack() {
        while (!first.empty())
            first.pop();
        while (!second.empty())
            second.pop();
    }
    // Push element x onto stack.
    void push(int x) {
        second.push(x);
        while (second.size() > 1) {
            first.push(second.front());
            second.pop();
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        top();
        second.pop();
    }
    
    // Get the top element.
    int top() {
        if (second.empty()) {
            for (int i = 0; i < first.size() - 1; i++) {
                first.push(first.front());
                first.pop();
            }
            second.push(first.front());
            first.pop();
        }
        return second.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return first.empty() && second.empty();
    }

private:
    queue<int> first, second;
};