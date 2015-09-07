class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int n = (int)low.length();
        int m = (int)high.length();
        if (n > m || (n == m && isBigger(low, high, n)))
            return 0;
        nums = vector<int>(N, 1);
        nums[1] = 3, nums[2] = 5;
        for (int i = 3; i < N; i++) {
            if (i & 1)
                nums[i] = nums[i - 1] * 3;
            else
                nums[i] = nums[i - 2] * 5;
        }
        total = vector<int>(N, 1);
        total[1] = 3, total[2] = 4;
        for (int i = 3; i < N; i++) {
            if (i & 1)
                total[i] = total[i - 1] * 3;
            else
                total[i] = total[i - 2] * 5;
        }
        int lless = calLess(low);
        int hless = calLess(high);
        int res = 0;
        for (int i = n + 1; i <= m - 1; i++)
            res += total[i];
        res += hless - lless;
        if (n != m)
            res += total[n];
        if (isStro(high))
            res++;
        return res;
    }

private:
    static const int N = 30, M = 5;
    char digits[M] = {'0', '1', '6', '8', '9'};
    vector<int> nums, total;
    bool isStro(const string &s) {
        int n = (int)s.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                if (!((s[i] == '6' && s[j] == '9') ||
                      (s[i] == '9' && s[j] == '6')))
                    break;
            } else {
                if (s[i] != '0' && s[i] != '1' && s[i] != '8')
                    break;
            }
            i++, j--;
        }
        return i > j;
    }
    bool isBigger(const string &s1, const string &s2, int l) {
        for (int i = 0; i < l; i++) {
            if (s1[i] == s2[i])
                continue;
            return s1[i] > s2[i];
        }
        return false;
    }
    void fillLeft(string &dst, int l, int r) {
        for (int i = r; i < dst.length(); i++, l--) {
            if (dst[l] == '0' || dst[l] == '1' || dst[l] == '8')
                dst[i] = dst[l];
            else if (dst[l] == '6')
                dst[i] = '9';
            else if (dst[l] == '9')
                dst[i] = '6';
        }
    }
    int calLess(const string &s) {
        int n = (int)s.length();
        if (n == 0)
            return 0;
        if (n == 1) {
            if (s[0] > '8')
                return 3;
            else if (s[0] > '1')
                return 2;
            else if (s[0] > '0')
                return 1;
            else
                return 0;
        }
        int i = 0, j = n - 1, res = 0;
        while (i < j) {
            int k =  i > 0 ? 0 : 1;
            while (digits[k] < s[i]) {
                k++;
                res += nums[j - i - 1];
            }
            if (digits[k] > s[i])
                return res;
            i++, j--;
        }
        string d(n, '0');
        for (int k = 0; k < i; k++)
            d[k] = s[k];
        if (i > j) {
            fillLeft(d, j, i);
            if (isBigger(s, d, n))
                res++;
        } else {
            d[i] = '0';
            fillLeft(d, j - 1, i + 1);
            if (isBigger(s, d, n))
                res++;
            d[i] = '1';
            fillLeft(d, j - 1, i + 1);
            if (isBigger(s, d, n))
                res++;
            d[i] = '8';
            fillLeft(d, j - 1, i + 1);
            if (isBigger(s, d, n))
                res++;
        }
        return res;
    }
};