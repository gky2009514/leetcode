class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int num = m + n;
        if (num & 1)
            return binaryFind(A, m, B, n, num / 2 + 1);
        else
            return (binaryFind(A, m, B, n, num / 2) + binaryFind(A, m, B, n, num / 2 + 1)) / 2;
        
    }
private:
    double binaryFind(int *a, int n, int *b, int m, int k) {
        if (m > n)
            return binaryFind(b, m, a, n, k);
        if (m == 0)
            return a[k - 1];
        if (k == 1)
            return min(a[0], b[0]);
        int r = min(k >> 1, m), l = k - r;
        if (a[l - 1] < b[r - 1])
            return binaryFind(a + l, n - l, b, m, k - l);
        else if (a[l - 1] > b[r - 1])
            return binaryFind(a, n, b + r, m - r, k - r);
        else
            return a[l - 1];
    }
};