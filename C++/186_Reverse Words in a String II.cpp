class Solution {
public:
    void reverseWords(string &s) {
        N = (int)s.length();
        reverse(s, 0, N - 1);
        int i = 0;
        while (i < N) {
            int j = i + 1;
            while (j < N && !isspace(s[j]))
                j++;
            reverse(s, i, j - 1);
            i = j + 1;
        }
    }
private:
    int N;
    void reverse(string &s, int st, int ed) {
        while (st < ed) {
            char c = s[st];
            s[st] = s[ed];
            s[ed] = c;
            st++, ed--;
        }
    }
};