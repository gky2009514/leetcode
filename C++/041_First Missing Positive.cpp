class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++) {
            while (A[i] != i && A[i] >= 0 && A[i] < n) {
                if (A[i] == A[A[i]])
                    break;
                swap(A, i, A[i]);
            }
        }
        for (int i = 1; i < n; i++) {
            if (A[i] != i)
                return i;
        }
        return A[0] == n ? n + 1 : n;
    }
private:
    void swap(int *A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
};