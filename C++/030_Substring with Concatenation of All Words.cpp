class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.length() == 0 || L.size() == 0 || L[0].length() == 0)
            return res;
        dict.clear();
        for (int i = 0; i < L.size(); i++)
            dict[L[i]]++;
        N = (int)S.length();
        M = (int)L[0].length();
        K = (int)L.size();
        for (int i = 0; i < M; i++) {
            int j = i, k = i;
            match.clear();
            while (j < N && k < N) {
                while (k < N && (k - j) / M < K) {
                    string s = S.substr(k, M);
                    if (dict.find(s) != dict.end()) {
                        if (match[s] + 1 > dict[s]) {
                            string t = S.substr(j, M);
                            match[t]--;
                            j += M;
                            break;
                        }
                        else
                            match[s]++;
                    }
                    else {
                        j = k = k + M;
                        match.clear();
                        break;
                    }
                    k += M;
                }
                if ((k - j) / M >= K) {
                    res.push_back(j);
                    string t = S.substr(j, M);
                    match[t]--;
                    j += M;
                }
            }
        }
        return res;
    }
private:
    int N, M, K;
    map<string, int> dict, match;
};