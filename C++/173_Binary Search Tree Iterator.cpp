class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *now = stk.top();
        stk.pop();
        pushLeft(now->right);
        return now->val;
    }
private:
    stack<TreeNode*> stk;
    void pushLeft(TreeNode *node) {
        if (node != NULL) {
            stk.push(node);
            while (node->left != NULL) {
                stk.push(node->left);
                node = node->left;
            }
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */