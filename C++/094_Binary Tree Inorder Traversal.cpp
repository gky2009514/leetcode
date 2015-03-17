class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        while (!stk.empty())
            stk.pop();
        while (1) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            if (stk.empty())
                break;
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
private:
    stack<TreeNode*> stk;
};