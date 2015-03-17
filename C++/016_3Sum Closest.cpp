class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3)
            return -1;
        sort(num.begin(), num.end());
        int res = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size(); i++) {
            int j = i + 1, k = (int)num.size() - 1;
            int tar = target - num[i];
            while (j < k) {
                if (abs(tar - num[j] - num[k]) < abs(target - res))
                    res = num[i] + num[j] + num[k];
                if (num[j] + num[k] == tar)
                    return res;
                else if (num[j] + num[k] < tar)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};