class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0)
            return res;
        int pos = 0;
        while (pos < nums.size())
            res.push_back(nextRange(pos, nums));
        return res;
    }

private:
    ostringstream oss;
    string nextRange(int &pos, const vector<int> &nums) {
        int st = pos, ed = pos + 1;
        while (ed < nums.size() && nums[ed] == nums[ed - 1] + 1)
            ed++;
        oss.str("");
        if (ed != st + 1)
            oss << nums[st] << "->" << nums[ed - 1];
        else
            oss << nums[st];
        pos = ed;
        return oss.str();
    }
};