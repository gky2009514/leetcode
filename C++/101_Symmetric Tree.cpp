class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL || left->val != right->val)
            return false;
        if (!isSymmetric(left->left, right->right))
            return false;
        return isSymmetric(left->right, right->left);
    }
};