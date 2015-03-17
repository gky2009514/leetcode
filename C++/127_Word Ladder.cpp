class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        map<string, bool> mp;
        mp.clear();
        queue<string> words;
        queue<int> steps;
        while (!words.empty())
            words.pop();
        while (!steps.empty())
            steps.pop();
        if (start.length() == 0 || end.length() == 0 || start == end)
            return 1;
        words.push(start);
        steps.push(1);
        mp[start] = true;
        while (!words.empty()) {
            string now = words.front();
            int nst = steps.front();
            words.pop();
            steps.pop();
            for (int i = 0; i < now.length(); i++) {
                char c = now[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    if (j == c)
                        continue;
                    now[i] = j;
                    if (now == end)
                        return nst + 1;
                    if (dict.find(now) != dict.end() && !mp[now]) {
                        mp[now] = true;
                        words.push(now);
                        steps.push(nst + 1);
                    }
                }
                now[i] = c;
            }
        }
        return 0;
    }
};