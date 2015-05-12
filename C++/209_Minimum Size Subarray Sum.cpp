class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s <= 0)
            return 1;
        int l = 0, r = 0;
        int sum = 0, min_len = INT_MAX;
        while (r < nums.size()) {
            sum += nums[r++];
            if (sum >= s) {
                while (l < r && sum - nums[l] >= s)
                    sum -= nums[l++];
                if (r - l == 1)
                    return 1;
                min_len = min(min_len, r - l);
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};