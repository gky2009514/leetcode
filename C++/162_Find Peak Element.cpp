class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() <= 1)
            return (int)num.size() - 1;
        int N = (int)num.size();
        if (num[0] > num[1])
            return 0;
        if (num[N - 1] > num[N - 2])
            return N - 1;
        for (int i = 1; i < N - 1; i++) {
            if (num[i] > num[i - 1] && num[i] > num[i + 1])
                return i;
        }
        return -1;
    }
};