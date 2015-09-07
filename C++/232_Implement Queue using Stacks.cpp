class Queue {
public:
    Queue() {
        while (!first.empty())
            first.pop();
        while (!second.empty())
            second.pop();
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        first.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (second.empty())
            moveToSecond();
        second.pop();
    }

    // Get the front element.
    int peek(void) {
        if (second.empty())
            moveToSecond();
        return second.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return first.empty() && second.empty();
    }

private:
    stack<int> first, second;
    
    void moveToSecond(void) {
        while (!first.empty()) {
            int t = first.top();
            first.pop();
            second.push(t);
        }
    }
};