class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        map<string, int> mp;
        int dist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] != word1 && words[i] != word2)
                continue;
            if (words[i] == word1 && mp.find(word2) != mp.end())
                dist = min(dist, abs(mp[word2] - i));
            if (words[i] == word2 && mp.find(word1) != mp.end())
                dist = min(dist, abs(mp[word1] - i));
            mp[words[i]] = i;
        }
        return dist;
    }
};