class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        while (!stk.empty())
            stk.pop();
        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0]) || tokens[i].length() > 1)
                stk.push(atoi(tokens[i].c_str()));
            else {
                int r = stk.top();
                stk.pop();
                int l = stk.top();
                stk.pop();
                switch(tokens[i][0]) {
                    case '+': stk.push(l + r); break;
                    case '-': stk.push(l - r); break;
                    case '*': stk.push(l * r); break;
                    case '/': stk.push(l / r); break;
                    default: break;
                }
            }
        }
        return stk.top();
    }
private:
    stack<int> stk;
};