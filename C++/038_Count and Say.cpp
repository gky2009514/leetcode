class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0)
            return nullptr;
        string s = "1";
        while (--n)
            get_next(s);
        return s;
    }
private:
    void get_next(string &s) {
        string tmp;
        tmp.clear();
        for (int i = 0; i < s.length(); ) {
            int j = i + 1;
            while (j < s.length() && s[j] == s[i])
                j++;
            tmp += (j - i) + '0';
            tmp += s[i];
            i = j;
        }
        s = tmp;
    }
};