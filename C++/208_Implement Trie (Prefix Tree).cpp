class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        word = '\0';
        is_end = false;
        next = vector<TrieNode*>(N, NULL);
    }
    char word;
    bool is_end;
    vector<TrieNode*> next;
private:
    const int N = 26;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string s) {
        if (s.length() == 0)
            return;
        TrieNode *now = root;
        for (int i = 0; i < s.length(); i++) {
            if (now->next[s[i] - 'a'] == NULL) {
                now->next[s[i] - 'a'] = new TrieNode();
                now->next[s[i] - 'a']->word = s[i];
            }
            now = now->next[s[i] - 'a'];
        }
        now->is_end = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string key) {
        if (key.length() == 0)
            return false;
        TrieNode *now = root;
        for (int i = 0; i < key.length(); i++) {
            if (now->next[key[i] - 'a'] == NULL)
                return false;
            now = now->next[key[i] - 'a'];
        }
        return now->is_end;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (prefix.length() == 0)
            return false;
        TrieNode *now = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (now->next[prefix[i] - 'a'] == NULL)
                return false;
            now = now->next[prefix[i] - 'a'];
        }
        return true;
    }
    
private:
    TrieNode* root;
};