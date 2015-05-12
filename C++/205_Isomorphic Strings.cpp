class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() <= 1)
            return true;
        int N = (int)s.length();
        map<char, char> mp;
        map<char, bool> isMap;
        for (int i = 0; i < N; i++) {
            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] != t[i])
                    return false;
            }
            else {
                if (isMap.find(t[i]) != isMap.end())
                    return false;
                mp[s[i]] = t[i];
                isMap[t[i]] = true;
            }
        }
        return true;
    }
};