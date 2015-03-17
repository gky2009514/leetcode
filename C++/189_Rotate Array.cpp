class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
private:
    void reverse(int nums[], int s, int t) {
        while (s < t) {
            int tmp = nums[s];
            nums[s] = nums[t];
            nums[t] = tmp;
            s++, t--;
        }
    }
};