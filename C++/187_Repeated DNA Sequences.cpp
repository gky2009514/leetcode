class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() > 10) {
            int occur[N];
            memset(occur, 0, sizeof(occur));
            int dna_num = 0;
            for (int i = 0; i < M; i++)
                dna_num = (dna_num << 2) + getNum(s[i]);
            occur[dna_num]++;
            for (int i = M; i < s.length(); i++) {
                dna_num = dna_num - (getNum(s[i - M]) << 18);
                dna_num = (dna_num << 2) + getNum(s[i]);
                if (occur[dna_num] == 1)
                    res.push_back(s.substr(i - M + 1, M));
                occur[dna_num]++;
            }
        }
        return res;
    }
private:
    const int N = 1050000;
    const int M = 10;
    int getNum(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return -1;
        }
    }
};