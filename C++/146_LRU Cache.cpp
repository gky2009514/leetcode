class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        lt.clear();
        mp.clear();
    }
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            lt.splice(lt.begin(), lt, it);
            mp[key] = lt.begin();
            return lt.begin()->val;
        }
        return -1;
    }
    void set(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (lt.size() == capacity) {
                mp.erase(lt.back().key);
                lt.pop_back();
            }
            lt.push_front(node(key, value));
            mp[key] = lt.begin();
        }
        else {
            auto it = mp[key];
            lt.splice(lt.begin(), lt, it);
            mp[key] = lt.begin();
            lt.begin()->val = value;
        }
    }
private:
    struct node {
        int key, val;
        node(int k, int v) : key(k), val(v) {}
    };
    int capacity;
    list<node> lt;
    map<int, list<node>::iterator> mp;
};