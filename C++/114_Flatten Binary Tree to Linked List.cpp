class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        pre = NULL;
        dfs(root);
    }
private:
    TreeNode *pre;
    void dfs(TreeNode *root) {
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        if (pre != NULL)
            pre->right = root;
        root->left = NULL;
        pre = root;
        if (l != NULL)
            dfs(l);
        if (r != NULL)
            dfs(r);
    }
};