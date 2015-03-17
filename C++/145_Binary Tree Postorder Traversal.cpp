class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;
        while (!stk.empty())
            stk.pop();
        while (root != NULL || !stk.empty()) {
            while (root != NULL) {
                stk.push(node(root));
                root = root->left;
            }
            if (stk.top().flag == false) {
                stk.top().flag = true;
                root = stk.top().root->right;
            }
            else {
                res.push_back(stk.top().root->val);
                stk.pop();
                root = NULL;
            }
        }
        return res;
    }
private:
    struct node {
        TreeNode *root;
        bool flag;
        node(TreeNode *r) : root(r), flag(false) {}
    };
    stack<node> stk;
};