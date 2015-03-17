class Solution {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> res;
        stringstream ss;
        if (n == 0) {
            if (lower == upper)
                ss << lower;
            else
                ss << lower << "->" << upper;
            res.push_back(ss.str());
            ss.str("");
            return res;
        }
        if (A[0] > lower) {
            if (A[0] == lower + 1)
                ss << lower;
            else
                ss << lower << "->" << A[0] - 1;
            res.push_back(ss.str());
            ss.str("");
        }
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && (A[j] == A[j - 1] || A[j] == A[j - 1] + 1))
                j++;
            if (j >= n)
                break;
            if (A[j] == A[j - 1] + 2)
                ss << A[j - 1] + 1;
            else
                ss << A[j - 1] + 1 << "->" << A[j] - 1;
            res.push_back(ss.str());
            ss.str("");
            i = j;
        }
        if (A[n - 1] < upper) {
            if (A[n - 1] == upper - 1)
                ss << upper;
            else
                ss << A[n - 1] + 1 << "->" << upper;
            res.push_back(ss.str());
            ss.str("");
        }
        return res;
    }
};