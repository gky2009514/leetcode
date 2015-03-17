class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        res.clear();
        int sum, carry = 1;
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            sum = digits[i] + carry;
            carry = sum / 10;
            res.push_back(sum % 10);
        }
        if (carry)
            res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};