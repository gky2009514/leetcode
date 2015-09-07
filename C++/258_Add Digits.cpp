class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        if (sum % 9 == 0)
            return 9;
        return sum % 9;
    }
};