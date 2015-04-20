class Solution {
    private String s, p;

    public boolean isMatch(String s, String p) {
        this.s = s;
        this.p = p;
        return isMatch(0, 0);
    }

    private boolean isMatch(int x, int y) {
        if (x >= s.length())
            return check(y);
        if (y >= p.length())
            return false;
        if (p.charAt(y) == '.' || p.charAt(y) == s.charAt(x)) {
            if (y + 1 < p.length() && p.charAt(y + 1) == '*') {
                if (p.charAt(y) == s.charAt(x)) {
                    do {
                        if (isMatch(x, y + 2))
                            return true;
                        x++;
                    } while (x < s.length() && p.charAt(y) == s.charAt(x));
                }
                else {
                    char c = s.charAt(x);
                    do {
                        if (isMatch(x, y + 2))
                            return true;
                        x++;
                    } while (x < s.length());
                }
                return isMatch(x, y + 2);
            }
            else
                return isMatch(x + 1, y + 1);
        }
        else if (y + 1 < p.length() && p.charAt(y + 1) == '*')
            return isMatch(x, y + 2);
        else
            return false;
    }

    private boolean check(int y) {
        if (y >= p.length())
            return true;
        while (y + 1 < p.length()) {
            if (p.charAt(y + 1) != '*')
                return false;
            y += 2;
        }
        return y >= p.length();
    }
}

public class Test {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isMatch("aa", "a"));
        System.out.println(s.isMatch("aa", "aa"));
        System.out.println(s.isMatch("aaa", "aa"));
        System.out.println(s.isMatch("aa", "a*"));
        System.out.println(s.isMatch("aa", ".*"));
        System.out.println(s.isMatch("ab", ".*"));
        System.out.println(s.isMatch("aab", "c*a*b"));
    }
}