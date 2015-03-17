class Solution {
public:
    void recoverTree(TreeNode *root) {
        pre = left = NULL;
        if (root != NULL) {
            if (!dfs(root)) {
                int tmp = left->val;
                left->val = pre->val;
                pre->val = tmp;
            }
        }
    }
private:
    TreeNode *pre, *left;
    bool dfs(TreeNode *root) {
        if (root->left != NULL && dfs(root->left))
            return true;
        if (pre != NULL) {
            if (left == NULL) {
                if (root->val < pre->val)
                    left = pre;
            }
            else if (pre->val < left->val && root->val >= left->val) {
                int tmp = left->val;
                left->val = pre->val;
                pre->val = tmp;
                return true;
            }
        }
        pre = root;
        if (root->right != NULL && dfs(root->right))
            return true;
        return false;
    }
};