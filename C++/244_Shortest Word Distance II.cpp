class WordDistance {
public:
    WordDistance(vector<string>& words) {
        mp.clear();
        for (int i = 0; i < words.size(); i++)
            mp.insert(pair<string, int>(words[i], i));
    }

    int shortest(string word1, string word2) {
        auto rag1 = mp.equal_range(word1);
        auto rag2 = mp.equal_range(word2);
        int dist = INT_MAX;
        for (auto it = rag1.first; it != rag1.second; it++) {
            for (auto jt = rag2.first; jt != rag2.second; jt++)
                dist = min(dist, abs(it->second - jt->second));
        }
        return dist;
    }

private:
    multimap<string, int> mp;
};