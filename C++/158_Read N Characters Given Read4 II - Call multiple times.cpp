class Solution {
public:
    Solution() : left(0) {
        
    }
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        if (left) {
            if (left >= n) {
                memcpy(buf, lastbuf, n);
                buf[n] = '\0';
                for (int i = 0; i < N - n;i++)
                    lastbuf[i] = lastbuf[i + n];
                left -= n;
                return n;
            }
            else {
                memcpy(buf, lastbuf, left);
                res += left;
                left = 0;
            }
        }
        char tmpbuf[N];
        int tmp;
        while ((tmp = read4(tmpbuf)) > 0) {
            if (res + tmp <= n) {
                memcpy(buf + res, tmpbuf, tmp);
                res += tmp;
            }
            else {
                int l = n - res;
                memcpy(buf + res, tmpbuf, l);
                buf[n] = '\0';
                left = tmp - l;
                memcpy(lastbuf, tmpbuf + l, left);
                return n;
            }
        }
        buf[res] = '\0';
        return res;
    }
private:
    static const int N = 5;
    int left;
    char lastbuf[N];
};