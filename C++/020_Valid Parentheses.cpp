class Solution {
public:
    bool isValid(string s) {
        char bpair[3][2] = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        bool flag[s.length() + 5];
        memset(flag, false, sizeof(flag));
        for (int i = 0; i < s.length(); i++) {
            int pos = 0;
            while (pos < 3 && s[i] != bpair[pos][1])
                pos++;
            if (pos >= 3)
                continue;
            for (int j = i - 1; j >= 0; j--) {
                if (!flag[j]) {
                    if (s[j] != bpair[pos][0])
                        return false;
                    flag[j] = flag[i] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (!flag[i])
                return false;
        }
        return true;
    }
};