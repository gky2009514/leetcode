class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
            return 0;
        sum = 0;
        dfs(root, 0);
        return sum;
    }
private:
    int sum;
    void dfs(TreeNode *root, int val) {
        val = val * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += val;
            return;
        }
        if (root->left != NULL)
            dfs(root->left, val);
        if (root->right != NULL)
            dfs(root->right, val);
    }
};