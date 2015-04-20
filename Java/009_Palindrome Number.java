class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        long left = 1, right = 10;
        while (left <= x)
            left *= 10;
        while (left > right) {
            long i = (long)x % left * 10 / left;
            long j = (long)x % right * 10 / right;
            if (i != j)
                return false;
            left /= 10;
            right *= 10;
        }
        return true;
    }
}

public class Test {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isPalindrome(232));
        System.out.println(s.isPalindrome(2342));
        System.out.println(s.isPalindrome(345543));
    }
}