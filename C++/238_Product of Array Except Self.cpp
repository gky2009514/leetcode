class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size(), 0);
        int n = (int)nums.size();
        product[0] = 1;
        for (int i = 1; i < n; i++)
            product[i] = product[i - 1] * nums[i - 1];
        int pt = 1;
        for (int i = n - 1; i >= 0; i--) {
            product[i] *= pt;
            pt *= nums[i];
        }
        return product;
    }
};