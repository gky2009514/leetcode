class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = (int)s.length();
        bool odd = n & 1;
        map<char, int> mp;
        for (int i = 0; i < n; i++)
            mp[s[i]]++;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second & 1) {
                if (odd)
                    odd = false;
                else
                    return false;
            }
        }
        return true;
    }
};