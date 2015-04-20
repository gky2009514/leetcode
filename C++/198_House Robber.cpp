class Solution {
public:
    int rob(vector<int> &num) {
        int a = 0, b = 0, na, nb;
        for (int i = 0; i < num.size(); i++) {
            na = b + num[i];
            nb = max(a, b);
            a = na, b = nb;
        }
        return max(a, b);
    }
};