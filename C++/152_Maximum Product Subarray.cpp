class Solution {
public:
    int maxProduct(int A[], int n) {
        ma = INT_MIN;
        int st = 0, ed = findZero(A, 0, n);
        while (ed < n) {
            ma = max(ma, 0);
            if (ed - st >= 1)
                calMax(A, st, ed);
            st = ed + 1;
            ed = findZero(A, ed + 1, n);
        }
        if (ed - st >= 1)
            calMax(A, st, ed);
        return ma;
    }
private:
    int ma;
    int findZero(int *A, int st, int n) {
        for (int i = st; i < n; i++) {
            if (A[i] == 0)
                return i;
        }
        return n;
    }
    void calMax(int *A, int st, int ed) {
        if (ed - st == 1) {
            ma = max(ma, A[st]);
            return;
        }
        long long pro = 1;
        for (int i = st; i < ed; i++)
            pro *= A[i];
        if (pro < 0) {
            long long l = pro, r = pro;
            int i = st;
            while (l < 0)
                l /= A[i++];
            i = ed - 1;
            while (r < 0)
                r /= A[i--];
            ma = max(ma, (int)max(l, r));
        }
        else
            ma = max(ma, (int)pro);
    }
};