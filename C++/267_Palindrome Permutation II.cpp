class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int n = (int)s.length();
        mp.clear();
        for (int i = 0; i < n; i++)
            mp[s[i]]++;
        str = string(n, '0');
        res.clear();
        bool odd = n & 1;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second & 1) {
                if (!odd)
                    return res;
                odd = false;
                it->second--;
                str[n >> 1] = it->first;
            }
        }
        this->n = n;
        m = n >> 1;
        dfs(0);
        return res;
    }

private:
    int n, m;
    string str;
    map<char, int> mp;
    vector<string> res;
    void dfs(int x) {
        if (x >= m) {
            res.push_back(str);
            return;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > 0) {
                it->second -= 2;
                str[x] = str[n - x - 1] = it->first;
                dfs(x + 1);
                it->second += 2;
            }
        }
    }
};