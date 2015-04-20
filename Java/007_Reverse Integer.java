class Solution {
    public int reverse(int x) {
        boolean sign = x >= 0;
        long tmp = (long)x;
        tmp = Math.abs(tmp);
        long res = 0;
        while (tmp > 0) {
            long digit = tmp % 10;
            tmp /= 10;
            res = res * 10 + digit;
        }
        if (sign) {
            if (res > Integer.MAX_VALUE)
                return 0;
            return (int)res;
        }
        else {
            if (-res < Integer.MIN_VALUE)
                return 0;
            return (int)-res;
        }
    }
}

public class Test {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.reverse(123));
        System.out.println(s.reverse(-123));
    }
}