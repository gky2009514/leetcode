class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int cross = 0;
        if (!(E >= C || G <= A || F >= D || H <= B)) {
            int yb = max(B, F), yt = min(D, H);
            int xl = max(A, E), xr = min(C, G);
            cross =  (yt - yb) * (xr - xl);
        }
        long long a1 = (long long)(C - A) * (D - B);
        long long a2 = (long long)(G - E) * (H - F);
        return (int)(a1 + a2 - cross);
    }
};