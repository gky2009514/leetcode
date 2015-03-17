class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
private:
    bool isValid(TreeNode *root, long long mi, long long ma) {
        if (root == NULL)
            return true;
        if (root->val <= mi || root->val >= ma)
            return false;
        return isValid(root->left, mi, root->val) && isValid(root->right, root->val, ma);
    }
};