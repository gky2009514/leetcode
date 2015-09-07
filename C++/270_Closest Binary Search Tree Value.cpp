class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (root == NULL)
            return -1;
        mi = abs(root->val - target);
        r = root;
        findCloset(root, target);
        return r->val;
    }

private:
    double mi;
    TreeNode *r;
    void findCloset(TreeNode *root, double target) {
        if (root == NULL)
            return;
        if (abs(target - root->val) < mi) {
            mi = abs(target - root->val);
            r = root;
        }
        if (root->val >= target)
            findCloset(root->left, target);
        else
            findCloset(root->right, target);
    }
};