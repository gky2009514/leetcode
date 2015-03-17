class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int sum, carry = 0;
        int i = (int)a.length() - 1, j = (int)b.length() - 1;
        while (i >= 0 && j >= 0) {
            sum = a[i--] - '0' + b[j--] - '0' + carry;
            carry = sum / 2;
            res += sum % 2 + '0';
        }
        while (i >= 0) {
            sum = a[i--] - '0' + carry;
            carry = sum / 2;
            res += sum % 2 + '0';
        }
        while (j >= 0) {
            sum = b[j--] - '0' + carry;
            carry = sum / 2;
            res += sum % 2 + '0';
        }
        if (carry)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};