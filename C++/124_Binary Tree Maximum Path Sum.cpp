class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root == NULL)
            return 0;
        int single = 0;
        return maxSum(root, single);
    }
private:
    int maxSum(TreeNode *root, int &single) {
        int left = 0, ma = root->val;
        if (root->left != NULL)
            ma = max(ma, maxSum(root->left, left));
        int right = 0;
        if (root->right != NULL)
            ma = max(ma, maxSum(root->right, right));
        single = max(left, right) + root->val;
        single = max(single, 0);
        return max(ma, left + root->val + right);
    }
};