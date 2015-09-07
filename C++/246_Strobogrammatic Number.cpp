class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = (int)num.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (num[i] != num[j]) {
                if (!((num[i] == '6' && num[j] == '9') ||
                      (num[i] == '9' && num[j] == '6')))
                    break;
            } else {
                if (num[i] != '0' && num[i] != '1' && num[i] != '8')
                    break;
            }
            i++, j--;
        }
        return i > j;
    }
};