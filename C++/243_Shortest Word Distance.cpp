class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        map<string, int> mp;
        int dist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1 || words[i] == word2)
                mp[words[i]] = i;
            if (mp.find(word1) != mp.end() && mp.find(word2) != mp.end())
                dist = min(dist, abs(mp[word1] - mp[word2]));
        }
        return dist;
    }
};