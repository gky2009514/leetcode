class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }
        return true;;
    }

private:
    static bool cmp(const Interval &a, const Interval &b) {
        if (a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    }
};