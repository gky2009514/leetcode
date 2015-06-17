class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->k = k - 1;
        return find(nums, 0, (int)nums.size() - 1);
    }

private:
    int k;
    int find(vector<int> &nums, int left, int right) {
        if (left == right)
            return nums[left];
        int l = left - 1, r = left;
        int senti = nums[right];
        while (r < right) {
            if (nums[r] > senti) {
                l++;
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
            }
            r++;
        }
        l++;
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
        if (l == k)
            return nums[l];
        else if (l < k)
            return find(nums, l + 1, right);
        else
            return find(nums, left, l - 1);
    }
};