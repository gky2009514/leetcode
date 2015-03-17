class Solution {
public:
    int majorityElement(vector<int> &num) {
        int res = 0, f = 0;
        for (int i = 0; i < num.size(); i++) {
            if (f == 0) {
                res = num[i];
                f++;
            }
            else if (num[i] == res)
                f++;
            else
                f--;
        }
        return res;
    }
};