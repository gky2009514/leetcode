class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = (int)citations.size();
        if (n == 0)
            return 0;
        sort(citations.begin(), citations.end());
        int res = -1;
        for (int i = 1; i < n; i++) {
            if (n - i <= citations[i] && n - i >= citations[i - 1])
                res = n - i;
        }
        if (res == -1 && n <= citations[0])
            res = n;
        return res == -1 ? 0 : res;
    }
};