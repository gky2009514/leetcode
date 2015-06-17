class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0)
            return false;
        vector<node> vt;
        for (int i = 0; i < nums.size(); i++)
            vt.push_back(node(nums[i], i));
        sort(vt.begin(), vt.end());
        for (int i = 0; i < vt.size(); i++) {
            for (int j = i + 1; j < vt.size() && vt[j].x - vt[i].x <= t; j++) {
                if (abs(vt[j].pos - vt[i].pos) <= k)
                    return true;
            }
        }
        return false;
    }

private:
    struct node {
        long long x;
        int pos;
        node(long long x, int p): x(x), pos(p) {}
        bool operator < (const node &a) const {
            if (x == a.x)
                return pos < a.pos;
            return x < a.x;
        }
    };
};