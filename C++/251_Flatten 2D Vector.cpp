class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        vect = vec2d;
        start = false;
    }
    
    int next() {
        return *jt++;
    }

    bool hasNext() {
        if (!start) {
            start = true;
            it = vect.begin();
            if (it == vect.end())
                return false;
            while (it != vect.end() && it->size() == 0)
                it++;
            if (it == vect.end())
                return false;
            jt = it->begin();
            return true;
        } else {
            while (jt == it->end()) {
                it++;
                if (it == vect.end())
                    break;
                jt = it->begin();
            }
            return !(it == vect.end());
        }
    }

private:
    bool start;
    vector<vector<int> > vect;
    vector<vector<int> >::iterator it;
    vector<int>::iterator jt;
};