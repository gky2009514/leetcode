class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.length() == 0)
            return vector<int>();
        vector<int> nums;
        vector<char> ope;
        int n = (int)input.length();
        for (int i = 0; i < n; ) {
            int j = i, num = 0;
            while (j < n && isdigit(input[j]))
                num = num * 10 + input[j++] - '0';
            nums.push_back(num);
            if (j < n)
                ope.push_back(input[j++]);
            i = j;
        }
        int m = (int)nums.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(m, vector<int>()));
        for (int i = 0; i < m; i++)
            dp[i][i].push_back(nums[i]);
        for (int k = 2; k <= m; k++) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = i; j < i + k - 1; j++) {
                    for (int it = 0; it < dp[i][j].size(); it++) {
                        for (int jt = 0; jt < dp[j + 1][i + k - 1].size(); jt++) {
                            int a = dp[i][j][it], b = dp[j + 1][i + k - 1][jt];
                            dp[i][i + k - 1].push_back(ope[j] == '*' ? a * b :
                                ope[j] == '+' ? a + b : a - b);
                        }
                    }
                }
            }
        }
        return dp[0][m - 1];
    }
};