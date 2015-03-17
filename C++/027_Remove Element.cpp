class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != elem)
                A[res++] = A[i];
        }
        return res;
    }
};