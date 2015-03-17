class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int pos = (int)num.size() - 1;
        while (pos > 0 && num[pos - 1] >= num[pos])
            pos--;
        if (pos == 0) {
            reverse(num.begin(), num.end());
            return;
        }
        int sp = pos;
        while (sp < num.size() && num[sp] > num[pos - 1])
            sp++;
        int tmp = num[pos - 1];
        num[pos - 1] = num[sp - 1];
        num[sp - 1] = tmp;
        int i = pos, j = (int)num.size() - 1;
        while (i < j) {
            tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
            i++, j--;
        }
    }
};