class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        if (root == NULL)
            return res;
        string s = to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(s);
            return res;
        }
        dfs(root->left, s);
        dfs(root->right, s);
        return res;
    }

private:
    vector<string> res;
    void dfs(TreeNode *root, string s) {
        if (root == NULL)
            return;
        s += "->" + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(s);
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
};