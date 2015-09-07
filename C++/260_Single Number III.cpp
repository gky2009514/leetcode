class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for (int i = 0; i < nums.size(); i++)
            xr ^= nums[i];
        long long bit = 1;
        while (!(xr & bit))
            bit <<= 1;
        int lr = 0, rr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & bit)
                lr ^= nums[i];
            else
                rr ^= nums[i];
        }
        vector<int> res;
        res.push_back(lr);
        res.push_back(rr);
        return res;
    }
};