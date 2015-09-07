class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> vote(2, 0), num(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == vote[0] && num[0])
                num[0]++;
            else if (nums[i] == vote[1] && num[1])
                num[1]++;
            else if (num[0] == 0) {
                vote[0] = nums[i];
                num[0] = 1;
            }
            else if (num[1] == 0) {
                vote[1] = nums[i];
                num[1] = 1;
            }
            else {
                num[0]--;
                num[1]--;
            }
        }
        vector<int> res;
        num[0] = num[1] = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == vote[0])
                num[0]++;
            else if (nums[i] == vote[1])
                num[1]++;
        }
        if (num[0] > nums.size() / 3)
            res.push_back(vote[0]);
        if (num[1] > nums.size() / 3)
            res.push_back(vote[1]);
        return res;
    }
};