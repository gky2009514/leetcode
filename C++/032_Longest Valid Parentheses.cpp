class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, N = (int)s.length();
        stack<int> stk;
        vector<bool> flag(N, false);
        for (int i = 0; i < N; i++) {
            if (s[i] == '(')
                stk.push(i);
            else {
                if (!stk.empty()) {
                    flag[i] = flag[stk.top()] = true;
                    stk.pop();
                }
            }
        }
        int i = 0;
        while (i < N) {
            while (i < N && !flag[i])
                i++;
            if (i >= N)
                break;
            int j = i;
            while (j < N && flag[j])
                j++;
            res = max(res, (j - i));
            i = j;
        }
        return res;
    }
};