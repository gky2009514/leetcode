class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        int N = (int)num.size();
        vector<vector<int> > res;
        res.clear();
        vector<int> now;
        for (int i = 0; i < N; i++) {
            if (i > 0 && num[i] == num[i - 1])
                continue;
            int j = i + 1, k = N - 1;
            int tar = -num[i];
            while (j < k) {
                if (num[j] + num[k] == tar) {
                    if (!(j > i + 1 && num[j] == num[j - 1]) && !(k < N - 1 && num[k] == num[k + 1])) {
                        now.clear();
                        now.push_back(num[i]);
                        now.push_back(num[j]);
                        now.push_back(num[k]);
                        res.push_back(now);
                    }
                    j++, k--;
                }
                else if (num[j] + num[k] < tar)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};