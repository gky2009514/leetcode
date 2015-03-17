class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        int pos[N + 5];
        memset(pos, -1, sizeof(pos));
        int ma = 1, now = 1;
        pos[s[0]] = 0;
        for (int i = 1; i < s.length(); i++) {
            now = min(now + 1, i - pos[s[i]]);
            pos[s[i]] = i;
            ma = max(ma, now);
        }
        return ma;
    }
private:
    const int N = 256;
};