class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        this->start = start;
        this->end = end;
        M = -1;
        bfs(dict);
        if (M == -1)
            return res;
        if (M == 0) {
            res.push_back(vector<string>(1, start));
            return res;
        }
        v.clear();
        dfs(M, res, dict);
        return res;
    }
private:
    int N, M;
    string start, end;
    vector<string> v;
    map<string, int> mp;
    void bfs(unordered_set<string> &dict) {
        if (start.length() == 0 || start == end) {
            M = 0;
            return;
        }
        queue<string> words;
        queue<int> steps;
        mp.clear();
        words.push(start);
        steps.push(0);
        mp[start] = 0;
        N = (int)start.length();
        while (!words.empty()) {
            string ft = words.front();
            int sp = steps.front();
            if (M != -1 && sp >= M)
                break;
            words.pop();
            steps.pop();
            for (int i = 0; i < N; i++) {
                char c = ft[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    if (j == c)
                        continue;
                    ft[i] = j;
                    if (ft == end) {
                        if (M == -1) {
                            M = sp + 1;
                            mp[ft] = M;
                        }
                        break;
                    }
                    if (dict.find(ft) != dict.end() && mp.find(ft) == mp.end()) {
                        mp[ft] = sp + 1;
                        words.push(ft);
                        steps.push(sp + 1);
                    }
                }
                ft[i] = c;
            }
        }
    }
    void dfs(int step, vector<vector<string> > &res, unordered_set<string> &dict) {
        if (step <= 0)
            return;
        v.push_back(end);
        for (int i = 0; i < N; i++) {
            char c = end[i];
            for (char j = 'a'; j <= 'z'; j++) {
                if (j == c)
                    continue;
                end[i] = j;
                if (start == end) {
                    v.push_back(start);
                    reverse(v.begin(), v.end());
                    res.push_back(v);
                    reverse(v.begin(), v.end());
                    v.pop_back();
                    break;
                }
                if (dict.find(end) != dict.end() && mp[end] == step - 1)
                    dfs(step - 1, res, dict);
            }
            end[i] = c;
        }
        v.pop_back();
    }
};