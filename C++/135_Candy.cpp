class Solution {
public:
    int candy(vector<int> &ratings) {
        int N = (int)ratings.size();
        if (N == 0)
            return 0;
        vector<int> left(N, 0), right(N, 0);
        int i = 0;
        while (i < N) {
            int j = i + 1;
            while (j < N && ratings[j] < ratings[j - 1])
                j++;
            for (int k = i; k < j; k++)
                right[k] = j - k - 1;
            i = j;
        }
        i = N - 1;
        while (i >= 0) {
            int j = i - 1;
            while (j >= 0 && ratings[j] < ratings[j + 1])
                j--;
            for (int k = i; k > j; k--)
                left[k] = k - j - 1;
            i = j;
        }
        int res = 0;
        for (i = 0; i < N; i++)
            res += max(left[i], right[i]) + 1;
        return res;
    }
};
