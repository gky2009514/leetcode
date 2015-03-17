class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0 || n == 1)
            return true;
        int maxsteps = A[0];
        for (int i = 1; i < n; i++) {
            if (maxsteps == 0)
                return false;
            maxsteps--;
            if (maxsteps < A[i])
                maxsteps = A[i];
            if (i + maxsteps >= n - 1)
                return true;
        }
        return false;
    }
};