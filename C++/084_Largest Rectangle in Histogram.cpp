class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        while (!stk.empty())
            stk.pop();
        int N = (int)height.size();
        vector<int> left(N, 0), right(N, 0);
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && stk.top().height > height[i]) {
                right[stk.top().pos] = i - 1;
                stk.pop();
            }
            stk.push(hist(i, height[i]));
        }
        while (!stk.empty()) {
            right[stk.top().pos] = N - 1;
            stk.pop();
        }
        for (int i = N - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top().height > height[i]) {
                left[stk.top().pos] = i + 1;
                stk.pop();
            }
            stk.push(hist(i, height[i]));
        }
        while (!stk.empty()) {
            left[stk.top().pos] = 0;
            stk.pop();
        }
        int res = 0;
        for (int i = 0; i < N; i++)
            res = max(res, height[i] * (right[i] - left[i] + 1));
        return res;
    }
private:
    struct hist {
        int pos, height;
        hist(int p, int h) : pos(p), height(h) {}
    };
    stack<hist> stk;
};
