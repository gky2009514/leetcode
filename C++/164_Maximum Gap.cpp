class Solution {
public:
    int maximumGap(vector<int> &num) {
        N = (int)num.size();
        if (N < 2)
            return 0;
        mp.clear();
        for (int i = 0; i < N; i++)
            mp[num[i]] = num[i];
        auto it = mp.begin();
        auto jt = ++it;
        it--;
        int res = 0;
        while (jt != mp.end()) {
            res = max(res, jt->first - it->first);
            it++, jt++;
        }
        return res;
    }
private:
    int N;
    map<int, int> mp;
};