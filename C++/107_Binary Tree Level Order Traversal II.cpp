class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > vlevel;
        vlevel.clear();
        queue<int> lev;
        queue<TreeNode*> node;
        while (!lev.empty())
            lev.pop();
        while (!node.empty())
            node.pop();
        if (root != NULL) {
            node.push(root);
            lev.push(1);
            while (!node.empty()) {
                vector<int> val;
                val.clear();
                int now = lev.front();
                while (!lev.empty() && lev.front() == now) {
                    val.push_back(node.front()->val);
                    pushQueue(lev, node, node.front(), now);
                    lev.pop();
                    node.pop();
                }
                vlevel.push_back(val);
            }
        }
        reverse(vlevel.begin(), vlevel.end());
        return vlevel;
    }
private:
    void pushQueue(queue<int> &lev, queue<TreeNode*> &node, TreeNode* &root, int now) {
        if (root->left != NULL) {
            lev.push(now + 1);
            node.push(root->left);
        }
        if (root->right != NULL) {
            lev.push(now + 1);
            node.push(root->right);
        }
    }
};