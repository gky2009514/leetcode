class Solution {
public:
    int numTrees(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res = res * ((i << 2) - 2) / (i + 1);
        return (int)res;
    }
};