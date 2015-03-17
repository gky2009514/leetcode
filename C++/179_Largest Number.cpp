class Solution {
public:
    string largestNumber(vector<int> &num) {
        if (num.size() == 0)
            return "";
        sort(num.begin(), num.end(), compare);
        if (num[0] == 0)
            return "0";
        int total = 0;
        for (int i = 0; i < num.size(); i++)
            total += length(num[i]);
        char *buf = new char[total + 10];
        char *now = buf;
        for (int i = 0; i < num.size(); i++) {
            int tmp = sprintf(now, "%d", num[i]);
            now += tmp;
        }
        *now = '\0';
        string s = buf;
        delete buf;
        return s;
    }
private:
    static bool compare(const int a, const int b) {
        long long anum = a * pow(10, length(b)) + b;
        long long bnum = b * pow(10, length(a)) + a;
        return anum > bnum;
    }
    static int length(int x) {
        int res = 0;
        do {
            res++;
            x /= 10;
        } while (x != 0);
        return res;
    }
};