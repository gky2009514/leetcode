class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        memset(used, false, sizeof(used));
        k--;
        for (int i = n; i > 1; i--) {
            int below = k / weight[i - 1];
            k %= weight[i - 1];
            s.append(1, getNum(below) + '0');
        }
        s.append(1, getNum(0) + '0');
        return s;
    }
private:
    int weight[9] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320};
    bool used[10];
    int getNum(int below) {
        for (int i = 1; i < 10; i++) {
            if (used[i] == false && below == 0) {
                used[i] = true;
                return i;
            }
            else if (used[i] == false)
                below--;
        }
        return -1;
    }
};