class Solution {
public:
    int numWays(int n, int k) {
        if (n <= 1 || k == 0)
            return n * k;
        int l1 = k * (k - 1), l2 = k;
        for (int i = 2; i < n; i++) {
            int n1 = (l1 + l2) * (k - 1);
            int n2 = l1;
            l1 = n1, l2 = n2;
        }
        return l1 + l2;
    }
};