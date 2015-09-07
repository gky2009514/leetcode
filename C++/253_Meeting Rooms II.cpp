class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pos> vp;
        for (int i = 0; i < intervals.size(); i++) {
            vp.push_back(pos(intervals[i].start, true));
            vp.push_back(pos(intervals[i].end, false));
        }
        sort(vp.begin(), vp.end());
        int num = 0, ma = 0;
        for (int i = 0; i < vp.size(); i++) {
            if (vp[i].st)
                num++;
            else
                num--;
            ma = max(ma, num);
        }
        return ma;
    }

private:
    struct pos {
        bool st;
        int x;
        pos(int x, bool s): x(x), st(s) {}
        bool operator < (const pos &a) const {
            if (x == a.x)
                return !st;
            return x < a.x;
        }
    };
};