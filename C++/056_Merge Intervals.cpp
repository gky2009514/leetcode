class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), compare);
        int N = (int)intervals.size();
        int i = 0;
        while (i < N) {
            Interval tmp(intervals[i].start, intervals[i].end);
            int j = i + 1;
            while (j < N && intervals[j].start <= tmp.end) {
                tmp.end = max(tmp.end, intervals[j].end);
                j++;
            }
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
private:
    static bool compare(const Interval &a, const Interval &b) {
        if (a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    }
};