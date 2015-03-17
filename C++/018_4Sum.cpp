class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        res.clear();
        int N = (int)num.size();
        for (int i = 0; i < N; i++) {
            if (i > 0 && num[i] == num[i - 1])
                continue;
            for (int j = i + 1; j < N; j++) {
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;
                int tar = target - num[i] - num[j];
                int k = j + 1, l = N - 1;
                while (k < l) {
                    if (num[k] + num[l] == tar) {
                        if (!(k > j + 1 && num[k] == num[k - 1]) && !(l < N - 1 && num[l] == num[l + 1]))
                            res.push_back({num[i], num[j], num[k], num[l]});
                        k++, l--;
                    }
                    else if (num[k] + num[l] < tar)
                        k++;
                    else
                        l--;
                }
            }
        }
        return res;
    }
};