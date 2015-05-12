class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        vector<bool> isPrime(n, false);
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (!isPrime[i]) {
                res++;
                for (int j = i << 1; j < n; j += i)
                    isPrime[j] = true;
            }
        }
        return res;
    }
};