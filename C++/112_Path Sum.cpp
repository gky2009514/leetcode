class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return false;
        if (root->val == sum && root->left == NULL && root->right == NULL)
            return true;
        sum -= root->val;
        if (hasPathSum(root->left, sum) || hasPathSum(root->right, sum))
            return true;
        return false;
    }
};