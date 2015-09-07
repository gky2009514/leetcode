class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = (int)citations.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (citations[m] >= n - m)
                r = m - 1;
            else
                l = m + 1;
        }
        return n - l;
    }
};