class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            int tar = target - nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] < tar) {
                    res += k - j;
                    j++;
                } else
                    k--;
            }
        }
        return res;
    }
};