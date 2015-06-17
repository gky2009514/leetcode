class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        if (board.size() == 0 || board[0].size() == 0)
            return res;
        N = (int)board.size();
        M = (int)board[0].size();
        this->board = board;
        this->words = words;
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        used = vector<bool>(words.size(), false);
        visit = vector<vector<bool> >(N, vector<bool>(M, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (root->next[board[i][j] - 'a'] != NULL) {
                    visit[i][j] = true;
                    dfs(i, j, root->next[board[i][j] - 'a']);
                    visit[i][j] = false;
                }
            }
        }
        return res;
    }
    
private:
    vector<vector<char> >board;
    vector<vector<bool> > visit;
    vector<string> words, res;
    vector<bool> used;
    int N, M;
    int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    class TrieNode {
    public:
        TrieNode() {
            end_index = -1;
            next = vector<TrieNode*>(26, NULL);
        }
        int end_index;
        vector<TrieNode*> next;
    };
    
    TrieNode* root;
        
    void insert(string s, int index) {
        if (s.length() == 0)
            return;
        TrieNode *now = root;
        for (int i = 0; i < s.length(); i++) {
            if (now->next[s[i] - 'a'] == NULL) {
                now->next[s[i] - 'a'] = new TrieNode();
            }
            now = now->next[s[i] - 'a'];
        }
        now->end_index = index;
    }
        
    void dfs(int x, int y, TrieNode *now) {
        if (now->end_index != -1) {
            if (!used[now->end_index])
                res.push_back(words[now->end_index]);
            used[now->end_index] = true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny])
                continue;
            if (now->next[board[nx][ny] - 'a'] != NULL) {
                visit[nx][ny] = true;
                dfs(nx, ny, now->next[board[nx][ny] - 'a']);
                visit[nx][ny] = false;
            }
        }
    }
};