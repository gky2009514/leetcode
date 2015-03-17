class Solution {
public:
    int singleNumber(int A[], int n) {
        int single = 0;
        for (int i = 0; i < n; i++)
            single ^= A[i];
        return single;
    }
};