class Solution {
    public int myAtoi(String str) {
        int index = 0;
        while (index < str.length() && Character.isSpaceChar(str.charAt(index)))
            index++;
        boolean sign = true;
        if (index < str.length()) {
            switch (str.charAt(index)) {
                case '-' : sign = false;
                case '+' : index++;
                default : break;
            }
        }
        long res = 0;
        while (index < str.length() && Character.isDigit(str.charAt(index))) {
            res = res * 10 + str.charAt(index) - '0';
            if (sign && res > Integer.MAX_VALUE)
                return Integer.MAX_VALUE;
            if (!sign && -res < Integer.MIN_VALUE)
                return Integer.MIN_VALUE;
            index++;
        }
        return sign ? (int)res : (int)-res;
    }
}

public class Test {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.myAtoi("   +2147483647"));
        System.out.println(s.myAtoi("-222222222222222"));
        System.out.println(s.myAtoi("-100"));
    }
}