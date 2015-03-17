class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
            return NULL;
        this->preorder = preorder;
        this->inorder = inorder;
        return build(0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
    }
private:
    vector<int> preorder, inorder;
    TreeNode *build(int pst, int ped, int ist, int ied) {
        if (pst > ped)
            return NULL;
        int rv = preorder[pst];
        int pos = ist;
        while (inorder[pos] != rv)
            pos++;
        TreeNode *root = new TreeNode(rv);
        root->left = build(pst + 1, pst + pos - ist, ist, pos - 1);
        root->right = build(ped + pos - ied + 1, ped, pos + 1, ied);
        return root;
    }
};