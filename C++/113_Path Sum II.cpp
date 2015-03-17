class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        res.clear();
        if (root != NULL) {
            now.clear();
            find(res, root, sum);
        }
        return res;
    }
private:
    vector<int> now;
    void find(vector<vector<int> > &res, TreeNode *root, int left) {
        now.push_back(root->val);
        left -= root->val;
        if (root->left == NULL && root->right == NULL && left == 0)
            res.push_back(now);
        if (root->left != NULL)
            find(res, root->left, left);
        if (root->right != NULL)
            find(res, root->right, left);
        now.pop_back();
    }
};