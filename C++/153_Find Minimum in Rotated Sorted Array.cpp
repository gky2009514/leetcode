class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 0)
            return -1;
        this->num = num;
        int N = (int)num.size() - 1;
        if (num[N] > num[0])
            return num[0];
        return find(0, N);
    }
private:
    vector<int> num;
    int find(int left, int right) {
        if (left >= right || num[right] > num[left])
            return num[left];
        int mid = left + ((right - left) >> 1);
        if (num[mid] > num[left])
            return find(mid + 1, right);
        else if (num[mid] == num[left])
            return min(num[left], num[right]);
        else
            return find(left, mid);
    }
};