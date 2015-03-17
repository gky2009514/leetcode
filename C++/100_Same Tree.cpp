class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == q)
            return true;
        if (p == NULL || q == NULL || p->val != q->val)
            return false;
        if (!isSameTree(p->left, q->left))
            return false;
        return isSameTree(p->right, q->right);
    }
};