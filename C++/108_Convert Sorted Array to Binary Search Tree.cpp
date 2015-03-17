class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num, 0, (int)num.size() - 1);
    }
private:
    TreeNode *build(vector<int> &num, int st, int ed) {
        if (st > ed)
            return NULL;
        int mid = st + ((ed - st) >> 1);
        TreeNode *root = new TreeNode(num[mid]);
        root->left = build(num, st, mid - 1);
        root->right = build(num, mid + 1, ed);
        return root;
    }
};