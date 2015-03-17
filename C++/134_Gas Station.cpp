class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0, st = 0, mi = 0;
        for (int i = 0; i < gas.size(); i++) {
            if (total < mi) {
                mi = total;
                st = i;
            }
            total += gas[i] - cost[i];
        }
        if (total < 0)
            return -1;
        if (total < mi)
            st = 0;
        return st;
    }
};