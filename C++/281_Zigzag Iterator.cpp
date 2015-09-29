class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.clear();
        v.push_back(v1), v.push_back(v2);
        it.clear();
        it.push_back(v[0].begin()), it.push_back(v[1].begin());
        index = 0;
    }
    
    int next() {
        int res = *it[index];
        it[index]++;
        index = (index + 1) % N;
        return res;
    }

    bool hasNext() {
        int i = 0;
        while (i < N) {
            if (it[index] != v[index].end())
                return true;
            index = (index + 1) % N;
            i++;
        }
        return false;
    }

private:
    static const int N = 2;
    int index;
    vector<vector<int>> v;
    vector<vector<int>::iterator> it;
};