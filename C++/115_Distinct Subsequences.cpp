class Solution {
public:
    int numDistinct(string S, string T) {
        M = (int)S.length();
        N = (int)T.length();
        if (N == 0)
            return 1;
        if (M == 0)
            return 0;
        vector<vector<int> > match(N + 1, vector<int>(M + 1, 0));
        for (int i = 1; i <= N; i++)
            match[i][0] = 0;
        for (int i = 0; i <= M; i++)
            match[0][i] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)
                match[i][j] = match[i][j - 1] + (T[i - 1] == S[j - 1] ? match[i - 1][j - 1] : 0);
        }
        return match[N][M];
    }
private:
    int N, M;
};