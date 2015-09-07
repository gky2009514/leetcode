class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> window;
        if (nums.size() == 0)
            return window;
        deque<ele> dq;
        for (int i = 0; i < k; i++) {
            while (!dq.empty()) {
                if (dq.back().num < nums[i])
                    dq.pop_back();
                else
                    break;
            }
            dq.push_back(ele(nums[i], i));
        }
        window.push_back(dq.front().num);
        for (int i = k; i < nums.size(); i++) {
            if (dq.front().pos == i - k)
                dq.pop_front();
            while (!dq.empty()) {
                if (dq.back().num < nums[i])
                    dq.pop_back();
                else
                    break;
            }
            dq.push_back(ele(nums[i], i));
            window.push_back(dq.front().num);
        }
        return window;
    }

private:
    typedef struct node {
        int num, pos;
        node(int n, int p): num(n), pos(p) {}
    }ele;
};