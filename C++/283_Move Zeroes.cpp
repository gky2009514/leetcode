class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 0)
            return;
        int left = - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                swap(nums[++left], nums[i]);
        }
    }
};