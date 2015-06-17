class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        if (buildings.size() == 0)
            return vector<pair<int, int> >();
        this->builds = buildings;
        return divideSky(0, static_cast<int>(buildings.size() - 1));
    }

private:
    vector<vector<int> > builds;
    vector<pair<int, int> > divideSky(int left, int right) {
        vector<pair<int, int> > res;
        if (left == right) {
            res.push_back(pair<int, int>(builds[left][0], builds[left][2]));
            res.push_back(pair<int, int>(builds[left][1], 0));
            return res;
        }
        int mid = left + ((right - left) >> 1);
        vector<pair<int, int> > ll = divideSky(left, mid);
        vector<pair<int, int> > rr = divideSky(mid + 1, right);
        merge(res, ll, rr);
        return res;
    }

    void merge(vector<pair<int, int> > &res, const vector<pair<int, int> > &ll, const vector<pair<int, int> > &rr) {
        int i = 0, j = 0, hl = 0, hr = 0, x;
        while (i < ll.size() && j < rr.size()) {
            if (ll[i].first < rr[j].first) {
                x = ll[i].first;
                hl = ll[i++].second;
            }
            else if (ll[i].first > rr[j].first) {
                x = rr[j].first;
                hr = rr[j++].second;
            }
            else {
                x = ll[i].first;
                hl = ll[i++].second;
                hr = rr[j++].second;
            }
            append(res, x, max(hl, hr));
        }
        while (i < ll.size()) {
            append(res, ll[i].first, ll[i].second);
            i++;
        }
        while (j < rr.size()) {
            append(res, rr[j].first, rr[j].second);
            j++;
        }
    }

    void append(vector<pair<int, int> > &res, int l, int h) {
        if (res.size() == 0) {
            res.push_back(pair<int, int>(l, h));
            return;
        }
        if (res[res.size() - 1].second == h)
            return;
        if (res[res.size() - 1].first == l) {
            res[res.size() - 1].second = max(res[res.size() - 1].second, h);
            return;
        }
        res.push_back(pair<int, int>(l, h));
    }
};