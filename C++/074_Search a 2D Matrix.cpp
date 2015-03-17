class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        N = (int)matrix.size();
        M = (int)matrix[0].size();
        int left = 0, right = N - 1;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (target >= matrix[mid][0] && target <= matrix[mid][M - 1])
                break;
            if (target < matrix[mid][0])
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (target >= matrix[mid][0] && target <= matrix[mid][M - 1]) {
            int l = 0, r = M - 1;
            int m;
            while (l <= r) {
                m = l + ((r - l) >> 1);
                if (matrix[mid][m] == target)
                    return true;
                if (target < matrix[mid][m])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return false;
    }
private:
    int N, M;
};