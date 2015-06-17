class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = getLeft(root->left);
        int rh = getRight(root->right);
        if (lh == rh)
            return (int)pow(2.0, lh + 1.0) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int getLeft(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }

    int getRight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->right;
        }
        return h;
    }
};