class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL)
            return 0;
        num = 0;
        dfs(root);
        return num;
    }

private:
    int num;
    bool dfs(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            num++;
            return true;
        }
        if (root->left == NULL) {
            if (dfs(root->right) && root->val == root->right->val) {
                num++;
                return true;
            }
            return false;
        }
        if (root->right == NULL) {
            if (dfs(root->left) && root->val == root->left->val) {
                num++;
                return true;
            }
            return false;
        }
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        if (l && r && root->val == root->left->val &&
            root->val == root->right->val) {
            num++;
            return true;
        }
        return false;
    }
};