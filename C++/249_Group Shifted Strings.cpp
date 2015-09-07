class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        multimap<string, bool> mp;
        for (int i = 0; i < strings.size(); i++)
            mp.insert(pair<string, bool>(strings[i], true));
        vector<vector<string> > res;
        for (int i = 0; i < strings.size(); i++) {
            auto rgi = mp.equal_range(strings[i]);
            if (!rgi.first->second)
                continue;
            vector<string> now;
            for (auto it = rgi.first; it != rgi.second; it++) {
                now.push_back(it->first);
                it->second = false;
            }
            for (int j = 1; j < N; j++) {
                for (int k = 0; k < strings[i].length(); k++) {
                    strings[i][k]++;
                    if (strings[i][k] > 'z')
                        strings[i][k] = 'a';
                }
                rgi = mp.equal_range(strings[i]);
                if (rgi.first == rgi.second)
                    continue;
                for (auto it = rgi.first; it != rgi.second; it++) {
                    now.push_back(it->first);
                    it->second = false;
                }
            }
            res.push_back(now);
        }
        for (int i = 0; i < res.size(); i++)
            sort(res[i].begin(), res[i].end());
        return res;
    }

private:
    static const int N = 26;
};