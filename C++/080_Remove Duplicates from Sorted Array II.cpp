class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len = 0;
        int pre = 0, now = 1;
        while (pre < n) {
            while (now < n && A[now] == A[pre])
                now++;
            for (int i = pre; i < n && i < pre + 2 && i < now; i++)
                A[len++] = A[i];
            pre = now;
            now = now + 1;
        }
        return len;
    }
};