class Solution {
public:
    string minWindow(string S, string T) {
        int appear[N];
        memset(appear, 0, sizeof(appear));
        M = (int)S.length();
        L = (int)T.length();
        if (M == 0 || M < L)
            return "";
        for (int i = 0; i < L; i++)
            appear[T[i]]++;
        int match[N];
        memset(match, 0, sizeof(match));
        int st = 0, ed = 0, num = 0;
        int index = -1, len;
        while (st < M) {
            while (num < L && ed < M) {
                match[S[ed]]++;
                if (match[S[ed]] <= appear[S[ed]])
                    num++;
                ed++;
            }
            if (num < L && ed >= M)
                break;
            if (index == -1) {
                index = st;
                len = ed - st;
            }
            else if (ed - st < len) {
                index = st;
                len = ed - st;
            }
            match[S[st]]--;
            if (match[S[st]] < appear[S[st]])
                num--;
            st++;
        }
        return index == -1 ? "" : S.substr(index, len);
    }
private:
    const int N = 256;
    int M, L;
};