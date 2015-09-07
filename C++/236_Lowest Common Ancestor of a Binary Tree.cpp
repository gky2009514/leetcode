class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode *lca = lowestCommonAncestor(root->left, p, q);
        TreeNode *rca = lowestCommonAncestor(root->right, p, q);
        if (lca != NULL && rca != NULL)
            return root;
        return lca == NULL ? rca : lca;
    }
};