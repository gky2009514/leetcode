class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0)
            return 0;
        this->inorder = inorder;
        this->postorder = postorder;
        return build(0, (int)inorder.size() - 1, 0, (int)postorder.size() - 1);
    }
private:
    vector<int> inorder, postorder;
    TreeNode *build(int ist, int ied, int pst, int ped) {
        if (ist > ied)
            return NULL;
        int rv = postorder[ped];
        TreeNode *root = new TreeNode(rv);
        int pos = ist;
        while (inorder[pos] != rv)
            pos++;
        root->left = build(ist, pos - 1, pst, pst + pos - ist - 1);
        root->right = build(pos + 1, ied, ped + pos - ied, ped - 1);
        return root;
    }
};