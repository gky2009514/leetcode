class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = (int)preorder.size();
        if (n <= 1)
            return true;
        stack<int> stk;
        int lower = INT_MIN;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] < lower)
                return false;
            while (!stk.empty() && stk.top() < preorder[i]) {
                lower = stk.top();
                stk.pop();
            }
            stk.push(preorder[i]);
        }
        return true;
    }
};