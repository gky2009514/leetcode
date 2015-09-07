class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0)
            return 0;
        long long sum = (long long)n * (n + 1) / 2;
        for (int i = 0; i < n; i++)
            sum -= nums[i];
        return (int)sum;
    }
};