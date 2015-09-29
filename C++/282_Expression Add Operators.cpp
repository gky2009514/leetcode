class Solution {
public:
    vector<string> addOperators(string num, int target) {
        now.clear(), res.clear();
        n = (int)num.length();
        if (n == 0)
            return res;
        this->num = num, this->target = target;
        dfs(0, 0, 0);
        return res;
    }

private:
    int n, target;
    string num;
    vector<string> res, now;
    void dfs(int pos, int value, int pre) {
        if (pos >= n) {
            if (value == target) {
                string t = "";
                for (int i = 0; i < now.size(); i++)
                    t += now[i];
                res.push_back(t);
            }
            return;
        }
        long long tmp = 0;
        string t = "";
        for (int i = pos; i < n; i++) {
            if (i > pos && tmp == 0)
                break;
            tmp = tmp * 10 + num[i] - '0';
            t += num[i];
            if (tmp > INT_MAX)
                break;
            if (now.empty()) {
                now.push_back(t);
                dfs(i + 1, (int)tmp, (int)tmp);
                now.pop_back();
            } else {
                if (value + tmp <= INT_MAX) {
                    now.push_back("+");
                    now.push_back(t);
                    dfs(i + 1, (int)(value + tmp), (int)tmp);
                    now.pop_back();
                    now.pop_back();
                }
                if (value - tmp >= INT_MIN) {
                    now.push_back("-");
                    now.push_back(t);
                    dfs(i + 1, (int)(value - tmp), -(int)tmp);
                    now.pop_back();
                    now.pop_back();
                }
                if (value + (tmp - 1) * pre <= INT_MAX) {
                    now.push_back("*");
                    now.push_back(t);
                    dfs(i + 1, (int)(value + (tmp - 1) * pre), (int)(tmp * pre));
                    now.pop_back();
                    now.pop_back();
                }
            }
        }
    }
};