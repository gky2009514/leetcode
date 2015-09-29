class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1)
            return n;
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                int j = nums[i];
                if (nums[j - 1] == j)
                    return j;
                swap(nums[i], nums[j - 1]);
            }
        }
        return 0;
    }
};