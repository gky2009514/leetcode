class TwoSum {
public:
    void add(int number) {
        ump[number]++;
    }
    bool find(int value) {
        for (auto left : ump) {
            int l = left.second;
            int r = value == (left.first << 1) ? l - 1 : ump.find(value - left.first) != ump.end();
            if (l && r)
                return true;
        }
        return false;
    }
private:
    unordered_map<int,int> ump;
};