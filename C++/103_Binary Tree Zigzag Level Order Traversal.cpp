class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        res.clear();
        if (root != NULL) {
            while (!ltor.empty())
                ltor.pop();
            while (!rtol.empty())
                rtol.pop();
            ltor.push(root);
            while (!ltor.empty()) {
                vector<int> now;
                now.clear();
                while (!ltor.empty()) {
                    TreeNode *fr = ltor.front();
                    ltor.pop();
                    now.push_back(fr->val);
                    if (fr->left != NULL)
                        rtol.push(fr->left);
                    if (fr->right != NULL)
                        rtol.push(fr->right);
                }
                res.push_back(now);
                now.clear();
                while (!rtol.empty()) {
                    TreeNode *fr = rtol.front();
                    rtol.pop();
                    now.push_back(fr->val);
                    if (fr->left != NULL)
                        ltor.push(fr->left);
                    if (fr->right != NULL)
                        ltor.push(fr->right);
                }
                if (now.size() > 0) {
                    reverse(now.begin(), now.end());
                    res.push_back(now);
                }
            }
        }
        return res;
    }
private:
    queue<TreeNode*> ltor, rtol;
};