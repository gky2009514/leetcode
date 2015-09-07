class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (p == NULL || q == NULL)
            return p == NULL ? q : p;
        if (p->val > q->val) {
            TreeNode *t = p;
            p = q;
            q = t;
        }
        if (root->val == p->val || root->val == q->val)
            return root->val == p->val ? p : q;
        if (root->val > p->val && root->val < q->val)
            return root;
        else if (root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};