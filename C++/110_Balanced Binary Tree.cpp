class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        if (abs(l - r) > 1)
            return false;
        if (isBalanced(root->left))
            return isBalanced(root->right);
        else
            return false;
    }
private:
    int getDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        return max(l, r) + 1;
    }
};