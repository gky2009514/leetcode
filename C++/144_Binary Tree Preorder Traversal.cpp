class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        v.clear();
        preorder(root);
        return v;
    }
private:
    vector<int> v;
    void preorder(TreeNode *root) {
        if (root == NULL)
            return;
        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};