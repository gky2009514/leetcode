class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int N = (int)intervals.size();
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (intervals[i].end < newInterval.start)
                res.push_back(intervals[i]);
            else if (intervals[i].start > newInterval.end) {
                if (!flag) {
                    flag = true;
                    res.push_back(newInterval);
                }
                res.push_back(intervals[i]);
            }
            else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if (!flag)
            res.push_back(newInterval);
        return res;
    }
};