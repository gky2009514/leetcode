class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL)
            return -1;
        int left = getNum(root->left);
        if (left == k - 1)
            return root->val;
        if (left > k - 1)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k - left - 1);
    }

private:
    int getNum(TreeNode* root) {
        if (root == NULL)
            return 0;
        return getNum(root->left) + 1 + getNum(root->right);
    }
};