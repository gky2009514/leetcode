class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int N = (int)words.size();
        int i = 0;
        while (i < N) {
            int len = (int)words[i].length();
            int j = i + 1;
            while (j < N && len + words[j].length() + j - i <= L) {
                len += words[j].length();
                j++;
            }
            string tmp = "";
            if (j >= N) {
                for (int k = i; k < j - 1; k++) {
                    tmp.append(words[k]);
                    tmp.append(1, ' ');
                }
                tmp.append(words[N - 1]);
                tmp.append(L - len - (j - i - 1), ' ');
            }
            else {
                if (j == i + 1) {
                    tmp = words[i];
                    tmp.append(L - len, ' ');
                }
                else {
                    int same = (L - len) / (j - i - 1);
                    int extra = (L - len) % (j - i - 1);
                    for (int k = i; k < j - 1; k++) {
                        int space = same;
                        if (extra) {
                            extra--;
                            space++;
                        }
                        tmp.append(words[k]);
                        tmp.append(space, ' ');
                    }
                    tmp.append(words[j - 1]);
                }
            }
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
};