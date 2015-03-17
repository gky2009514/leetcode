class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char tmpbuf[5];
        int tmp, res = 0;
        while ((tmp = read4(tmpbuf)) > 0) {
            memcpy(buf + res, tmpbuf, tmp);
            res += tmp;
            if (res >= n) {
                buf[n] = '\0';
                return n;
            }
        }
        buf[res] = '\0';
        return res;
    }
};