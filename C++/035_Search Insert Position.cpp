class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0)
            return 0;
        int l = 0, r = n - 1;
        int m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (A[m] == target)
                return m;
            if (A[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};