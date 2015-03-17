class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (l == 0)
            return r + 1;
        else if (r == 0)
            return l + 1;
        else
            return min(l, r) + 1;
    }
};