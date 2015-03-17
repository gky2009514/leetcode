class Solution {
public:
    int trap(int A[], int n) {
        int res = 0;
        while (!stk.empty())
            stk.pop();
        int height;
        for (int i = 0; i < n; i++) {
            if (stk.empty()) {
                height = A[i];
                stk.push(A[i]);
            }
            else if (A[i] <= stk.top())
                stk.push(A[i]);
            else {
                if (A[i] >= height) {
                    while (!stk.empty()) {
                        int tmp = stk.top();
                        res += height - tmp;
                        stk.pop();
                    }
                    height = A[i];
                }
                else {
                    int num = 0;
                    do {
                        int tmp = stk.top();
                        num++;
                        res += A[i] - tmp;
                        stk.pop();
                    } while(stk.top() < A[i]);
                    for (int j = 0; j < num; j++)
                        stk.push(A[i]);
                }
                stk.push(A[i]);
            }
        }
        return res;
    }
private:
    stack<int> stk;
};