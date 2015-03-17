class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        N = (int)s.length();
        if (N <= 2)
            return N;
        mp.clear();
        int l = 0, r = 0, dist = 0;
        int res = 0;
        while (l < N) {
            while (r < N && dist <= 2) {
                if (mp.find(s[r]) == mp.end() || mp[s[r]] == 0) {
                    dist++;
                    mp[s[r]] = 1;
                }
                else
                    mp[s[r]]++;
                r++;
                if (dist <= 2)
                    res = max(res, r - l);
            }
            if (dist > 2) {
                while (dist > 2) {
                    mp[s[l]]--;
                    if (mp[s[l]] == 0)
                        dist--;
                    l++;
                }
                res = max(res, r - l);
            }
            else
                break;
        }
        return res;
    }
private:
    int N;
    map<char, int> mp;
};