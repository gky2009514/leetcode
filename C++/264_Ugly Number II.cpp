class Solution {
public:
    int nthUglyNumber(int n) {
        queue<long long> q2, q3, q5;
        q2.push(2), q3.push(3), q5.push(5);
        long long num = 1;
        while (--n) {
            num = min(q2.front(), min(q3.front(), q5.front()));
            if (num == q2.front()) {
                q2.pop();
                q2.push(num * 2);
                q3.push(num * 3);
                q5.push(num * 5);
            } else if (num == q3.front()) {
                q3.pop();
                q3.push(num * 3);
                q5.push(num * 5);
            } else {
                q5.pop();
                q5.push(num * 5);
            }
        }
        return (int)num;
    }
};