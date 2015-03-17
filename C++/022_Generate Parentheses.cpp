class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        char *s = new char[(n << 1) + 1];
        s[n << 1] = '\0';
        res.clear();
        gen(res, s, 0, n, n);
        return res;
    }
    
    void gen(vector <string> &v, char *s, int x, int l, int r) {
        if (0 == l && 0 == r) {
            v.push_back(s);
            return ;
        }
        if (l) {
            s[x] = '(';
            gen(v, s, x + 1, l - 1, r);
        }
        if (r > l) {
            s[x] = ')';
            gen(v, s, x + 1, l, r - 1);
        }
    }
};