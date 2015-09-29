bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n <= 0)
            return -1;
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (isBadVersion(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};