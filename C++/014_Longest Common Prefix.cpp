class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        string res = prefix(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++)
            res = prefix(res, strs[i]);
        return res;
    }
private:
    string prefix(const string &s1, const string &s2) {
        string res = "";
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])
                break;
            res += s1[i];
        }
        return res;
    }
};