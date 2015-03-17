class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (root == NULL || root->left == NULL)
            return root;
        flip(root);
        return res;
    }
private:
    TreeNode *res;
    TreeNode *flip(TreeNode *root) {
        if (root->left == NULL) {
            res = root;
            return root;
        }
        TreeNode *p = flip(root->left);
        p->right = root;
        p->left = root->right;
        root->left = root->right = NULL;
        return root;
    }
};