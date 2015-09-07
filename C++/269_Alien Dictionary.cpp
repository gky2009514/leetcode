class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<bool> appear(N, false);
        int n = (int)words.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (!appear[words[i][j] - 'a'])
                    num++;
                appear[words[i][j] - 'a'] = true;
            }
        }
        indeg = vector<int>(N, 0);
        edges = vector<vector<bool> >(N, vector<bool>(N, false));
        for (int i = 0; i < n - 1; i++) {
            if (!cmpStr(words[i], words[i + 1]))
                return "";
        }
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (appear[i] && indeg[i] == 0) {
                appear[i] = false;
                q.push(i);
            }
        }
        string res = "";
        while (!q.empty()) {
            int ft = q.front();
            q.pop();
            res += ft + 'a';
            for (int i = 0; i < N; i++) {
                if (!appear[i])
                    continue;
                if (edges[ft][i]) {
                    indeg[i]--;
                    if (indeg[i] == 0) {
                        appear[i] = false;
                        q.push(i);
                    }
                }
            }
        }
        if (res.length() == num)
            return res;
        else
            return "";
    }

private:
    static const int N = 26;
    vector<int> indeg;
    vector<vector<bool> > edges;
    bool cmpStr(const string &s1, const string &s2) {
        int l1 = (int)s1.length();
        int l2 = (int)s2.length();
        for (int i = 0; i < l1 && i < l2; i++) {
            if (s1[i] == s2[i])
                continue;
            indeg[s2[i] - 'a']++;
            edges[s1[i] - 'a'][s2[i] - 'a'] = true;
            return true;
        }
        return l2 >= l1;
    }
};