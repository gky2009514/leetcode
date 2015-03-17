class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int, int> mp;
        for (int i = 0; i < num.size(); i++)
            mp[num[i]] = num[i];
        int res = 0;
        auto it = mp.begin();
        while (it != mp.end()) {
            auto jt = it;
            auto kt = ++jt;
            jt--;
            int num = 1;
            while (kt != mp.end() && kt->first - jt->first == 1) {
                jt++, kt++;
                num++;
            }
            res = max(res, num);
            it = kt;
        }
        return res;
    }
};