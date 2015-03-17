class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> mp;
        mp.clear();
        int N = (int)numbers.size();
        for (int i = 0; i < N; i++)
            mp[numbers[i]] = i;
        vector<int> res;
        res.clear();
        for (int i = 0; i < N; i++) {
            int tar = target - numbers[i];
            if (mp.find(tar) != mp.end() && mp[tar] > i) {
                res.push_back(i + 1);
                res.push_back(mp[tar] + 1);
                return res;
            }
        }
        return res;
    }
};