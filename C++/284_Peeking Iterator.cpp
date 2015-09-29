class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        cache = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (cache)
            return nt;
        nt = Iterator::next();
        cache = true;
        return nt;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (cache) {
            cache = false;
            return nt;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        if (cache)
            return true;
        return Iterator::hasNext();
    }

private:
    bool cache;
    int nt;
};