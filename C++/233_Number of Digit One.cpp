class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        int count = 0;
        int base = 1, after = 0;
        while (n) {
            int d = n % 10;
            n /= 10;
            count += n * base;
            if (d > 1)
                count += base;
            else if (d == 1)
                count += after + 1;
            after = after + base * d;
            base *= 10;
        }
        return count;
    }
};