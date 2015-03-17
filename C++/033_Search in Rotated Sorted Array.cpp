class Solution {
public:
    int search(int A[], int n, int target) {
        if (1 >= n) {
            if (A[0] == target)
                return 0;
            else
                return -1;
        }
        if (2 == n) {
            if (A[0] == target)
                return 0;
            if (A[1] == target)
                return 1;
            return -1;
        }
        int mid = (n - 1) >> 1;
        if (A[mid] == target)
            return mid;
        if (A[mid] > A[0]) {
            if (target >= A[0] && target < A[mid])
                return search(A, mid, target);
            else {
                int tmp = search(A + mid + 1, n - mid - 1, target);
                return -1 == tmp ? tmp : tmp + mid + 1;
            }
        }
        else {
            if (target > A[mid] && target <= A[n - 1]) {
                int tmp = search(A + mid + 1, n - mid - 1, target);
                return -1 == tmp ? tmp : tmp + mid + 1;
            }
            else
                return search(A, mid, target);
        }
    }
};