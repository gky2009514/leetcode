class Solution {
public:
    string simplifyPath(string path) {
        N = (int)path.length();
        if (N == 0)
            return "";
        int i = 0;
        while (!stk.empty())
            stk.pop();
        while (i < N) {
            int j = i + 1;
            while (j < N && path[j] != '/')
                j++;
            if (!((j - i == 2 && path[i + 1] == '.') || j - i == 1)) {
                if (j - i == 3 && path[i + 1] == '.' && path[i + 2] == '.') {
                    if (!stk.empty())
                        stk.pop();
                }
                else
                    stk.push(path.substr(i, j - i));
            }
            i = j;
        }
        string s = stk.empty() ? "/" : "";
        while (!stk.empty()) {
            s.insert(s.begin(), stk.top().begin(), stk.top().end());
            stk.pop();
        }
        return s;
    }
private:
    int N;
    stack<string> stk;
};