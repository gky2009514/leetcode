class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if (n == 0) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int left = 0, right = n - 1;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (A[mid] == target)
                break;
            if (A[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (A[mid] == target) {
            left = mid - 1;
            while (left >= 0 && A[left] == target)
                left--;
            left++;
            right = mid + 1;
            while (right < n && A[right] == target)
                right++;
            right--;
        }
        else
            left = right = -1;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};