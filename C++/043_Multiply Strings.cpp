class Solution {
public:
    string multiply(string num1, string num2) {
        N = (int)num1.length();
        M = (int)num2.length();
        string res(N + M, '0');
        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                int k = i + 1 + j;
                int tmp = (num1[i] - '0') * (num2[j] - '0') + res[k] - '0';
                res[k] = tmp % 10 + '0';
                int carry = res[k - 1] - '0' + tmp / 10;
                do {
                    res[k - 1] = carry % 10 + '0';
                    k--;
                    carry = res[k - 1] - '0' + carry / 10;
                } while(carry >= 10);
                res[k - 1] = carry % 10 + '0';
            }
        }
        int i = 0;
        while (i < N + M && res[i] == '0')
            i++;
        if (i >= N + M)
            return "0";
        return res.substr(i, N + M - i);
    }
private:
    int N, M;
};