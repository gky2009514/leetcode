class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
        int pre, res = 0;
        pre = A[res++] = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i] != pre) {
                pre = A[i];
                A[res++] = A[i];
            }
        }
        return res;
    }
};