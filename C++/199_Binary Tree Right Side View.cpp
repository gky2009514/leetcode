class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> node;
        queue<int> level;
        node.push(root);
        level.push(0);
        while (!node.empty()) {
            TreeNode *now = node.front();
            node.pop();
            int nl = level.front();
            level.pop();
            if (nl >= res.size())
                res.push_back(now->val);
            else
                res[nl] = now->val;
            if (now->left != NULL) {
                node.push(now->left);
                level.push(nl + 1);
            }
            if (now->right != NULL) {
                node.push(now->right);
                level.push(nl + 1);
            }
        }
        return res;
    }
};