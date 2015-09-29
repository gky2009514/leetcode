class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL)
            return NULL;
        if (p->right) {
            TreeNode *res = p->right;
            while (res->left)
                res = res->left;
            return res;
        }
        while (!stk.empty())
            stk.pop();
        find(root, p);
        while (!stk.empty()) {
            TreeNode *tp = stk.top();
            if (tp->right && tp->right->val == p->val) {
                p = tp;
                stk.pop();
            } else {
                break;
            }
        }
        if (stk.empty())
            return NULL;
        return stk.top();
    }

private:
    stack<TreeNode*> stk;
    void find(TreeNode *root, TreeNode *p) {
        if (root->val == p->val)
            return;
        stk.push(root);
        if (root->val < p->val)
            find(root->right, p);
        else
            find(root->left, p);
    }
};