class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        n--;
        do {
            int tmp = n % 26;
            s += tmp + 'A';
            n = n / 26 - 1;
        } while(n >= 0);
        reverse(s.begin(), s.end());
        return s;
    }
};