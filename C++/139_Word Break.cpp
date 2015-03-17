class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> check(s.length() + 1, false);
        check[0] = true;
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (check[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    check[i] = true;
                    break;
                }
            }
        }
        return check[s.length()];
    }  
};