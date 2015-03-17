class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0)
            return res;
        this->digits = digits;
        dfs(0, "", res);
        return res;
    }
private:
    string digits;
    const string dgal[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(int pos, string now, vector<string> &res) {
        if (pos >= digits.length()) {
            res.push_back(now);
            return;
        }
        int j = digits[pos] - '0';
        if (j > 1 && j < 10) {
            for (int i = 0; i < dgal[j].length(); i++)
                dfs(pos + 1, now + dgal[j][i], res);
        }
        else
            dfs(pos + 1, now, res);
    }
};