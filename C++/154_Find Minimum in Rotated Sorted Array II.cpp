class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 0)
            return 0;
        N = (int)num.size();
        return find(num, 0, N - 1);
    }
private:
    int N;
    int find(vector<int> &num, int l, int r) {
        if (r - l == 0)
            return num[l];
        if (r - l == 1)
            return min(num[l], num[r]);
        if (num[l] < num[r])
            return num[l];
        if (num[l] == num[r]) {
            int i = l + 1;
            while (i <= r && num[i] == num[l])
                i++;
            return i > r ? num[l] : find(num, i, r);
        }
        int mid = l + ((r - l) >> 1);
        if (num[mid] <= num[r])
            return find(num, l, mid);
        else
            return find(num, mid + 1, r);
    }
};