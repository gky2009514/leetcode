class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0)
            return 0;
        if (num.size() == 1)
            return num[0];
        if (num.size() == 2)
            return max(num[0], num[1]);
        int a = num[0], b = num[0], na, nb;
        for (int i = 2; i < num.size() - 1; i++) {
            na = b + num[i];
            nb = max(a, b);
            a = na, b = nb;
        }
        int res = max(a, b);
        a = 0, b = 0;
        for (int i = 1; i < num.size(); i++) {
            na = b + num[i];
            nb = max(a, b);
            a = na, b = nb;
        }
        return max(res, max(a, b));
    }
};