class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        N = (int)strlen(s);
        M = (int)strlen(p);
        if (M == 0)
            return N == 0;
        if (N == 0)
            return M == 1 && p[0] == '*';
        l = s, r = p;
        if (!canMatch())
            return false;
        vector<bool> pre(M + 1, false);
        vector<bool> match(M + 1, false);
        vector<bool> total(M + 1, false);
        match[M] = r[M - 1] == '*';
        bool first = false;
        for (int i = M - 1; i >= 0; i--) {
            if (r[i] == '*')
                match[i] = i == M - 1 || match[i + 1];
            else if ((r[i] == l[N - 1] || r[i] == '?') && !first) {
                first = true;
                match[i] = i == M - 1 || match[i + 1];
            }
            else
                match[i] = false;
        }
        for (int i = N - 2; i >= 0; i--) {
            for (int j = M; j >= 0; j--) {
                pre[j] = match[j];
                total[j] = total[j] || match[j];
            }
            for (int j = M - 1; j >= 0; j--) {
                if (r[j] == '*')
                    match[j] = match[j + 1] || total[j];
                else if (r[j] == '?' || r[j] == l[i])
                    match[j] = pre[j + 1];
                else
                    match[j] = false;
            }
        }
        return match[0];
    }
private:
    int N, M;
    const char *l, *r;
    bool canMatch(void) {
        int num = 0;
        for (int i = 0; i < M; i++) {
            if (r[i] != '*')
                num++;
        }
        return num <= N;
    }
};