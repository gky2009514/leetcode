class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
private:
    vector<TreeNode *> generate(int st, int ed) {
        vector<TreeNode *> res;
        if (st > ed) {
            res.push_back(NULL);
            return res;
        }
        for (int i = st; i <= ed; i++) {
            vector<TreeNode *> l = generate(st, i - 1);
            vector<TreeNode *> r = generate(i + 1, ed);
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = copy(l[j]);
                    root->right = copy(r[k]);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    TreeNode *copy(TreeNode *root) {
        if (root == NULL)
            return NULL;
        TreeNode *res = new TreeNode(root->val);
        res->left = copy(root->left);
        res->right = copy(root->right);
        return res;
    }
};