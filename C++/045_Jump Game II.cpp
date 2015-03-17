class Solution {
public:
    int jump(int A[], int n) {
        int steps = 0, pre = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (i > right)
                return -1;
            if (i > pre) {
                pre = right;
                steps++;
            }
            right = max(right, A[i] + i);
        }
        return steps;
    }
};