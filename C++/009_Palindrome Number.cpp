class Solution {
public:
    bool isPalindrome(int x) {
        long long left = 1, right = 10;
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        while (x >= left)
            left *= 10;
        while (left > right) {
            int i = (x % left) * 10 / left;
            int j = (x % right) * 10 / right;
            if (i != j)
                return false;
            left /= 10;
            right *= 10;
        }
        return true;
    }
};