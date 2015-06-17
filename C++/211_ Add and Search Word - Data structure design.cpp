class WordDictionary {
public:
    WordDictionary() {
        tr = new Trie();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        tr->insert(word);
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word.length() == 0)
            return false;
        return tr->search(tr->root, word, 0);
    }
    
private:
    
    class TrieNode {
    public:
        TrieNode() {
            word = '\0';
            is_end = false;
            next = vector<TrieNode*>(26, NULL);
        }
        char word;
        bool is_end;
        vector<TrieNode*> next;
    };
    
    class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }
        
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
        
        bool search(TrieNode *root, const string &key, int x) {
            if (x >= key.length())
                return root->is_end;
            if (key[x] == '.') {
                for (int i = 0; i < 26; i++) {
                    if (root->next[i] && search(root->next[i], key, x + 1))
                        return true;
                }
                return false;
            }
            else {
                if (root->next[key[x] - 'a'] == NULL)
                    return false;
                return search(root->next[key[x] - 'a'], key, x + 1);
            }
        }

        TrieNode* root;
    };
    
    Trie *tr;
};