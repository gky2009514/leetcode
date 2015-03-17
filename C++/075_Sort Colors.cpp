class Solution {
public:
    void sortColors(int A[], int n) {
        int rf, wf, bf;
        rf = -1, bf = n, wf = 0;
        while (wf < bf) {
            if (0 == A[wf]) {
                swap(A[++rf], A[wf]);
                wf++;
            }
            else if (1 == A[wf])
                wf++;
            else
                swap(A[--bf], A[wf]);
        }
    }
};