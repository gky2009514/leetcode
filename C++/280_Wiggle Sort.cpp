class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1)
            return;
        int k = (n & 1) ? (n + 1) >> 1 : n >> 1;
        findKth(0, n - 1, k, nums);
        for (int i = 1, j = k; j < n; j++) {
            if (j & 1)
                continue;
            swap(nums[i], nums[j]);
            i += 2;
        }
    }

private:
    void findKth(int l, int r, int k, vector<int> &nums) {
        if (l >= r)
            return;
        int left = l - 1;
        for (int i = l; i < r; i++) {
            if (nums[i] <= nums[r])
                swap(nums[++left], nums[i]);
        }
        swap(nums[++left], nums[r]);
        if (k == left)
            return;
        if (k < left)
            findKth(l, left - 1, k, nums);
        else
            findKth(left + 1, r, k, nums);
    }
};