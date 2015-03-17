class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        mp.clear();
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (mp.find(tmp) != mp.end()) {
                if (mp[tmp] != -1) {
                    res.push_back(strs[mp[tmp]]);
                    mp[tmp] = -1;
                }
                res.push_back(strs[i]);
            }
            else
                mp[tmp] = i;
        }
        return res;
    }
private:
    map<string, int> mp;
};