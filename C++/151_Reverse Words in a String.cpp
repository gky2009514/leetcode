class Solution {
public:
    void reverseWords(string &s) {
        int N = (int)s.length();
        char *str = new char[N + 5];
        reverse(0, N - 1, s);
        int len = 0;
        for (int i = 0; i < N; ) {
            int j = i;
            while (j < N && !isspace(s[j]))
                j++;
            if (j - 1 >= i) {
                reverse(i, j - 1, s);
                for (int k = i; k < j; k++)
                    str[len++] = s[k];
                str[len++] = ' ';
            }
            while (j < N && isspace(s[j]))
                j++;
            i = j;
        }
        if (len > 0)
            str[len - 1] = '\0';
        else
            str[0] = '\0';
        s = str;
        delete str;
    }
private:
    void reverse(int st, int ed, string &s) {
        while (st < ed) {
            char c = s[st];
            s[st] = s[ed];
            s[ed] = c;
            st++, ed--;
        }
    }
};