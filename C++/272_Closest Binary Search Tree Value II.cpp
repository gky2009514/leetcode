class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        res.clear();
        if (root == NULL)
            return res;
        this->k = k, this->target = target;
        mi = abs(target - root->val);
        r = root;
        findCloset(root);
        res.push_back(r->val);
        TreeNode *pre = getPredecessor(root, r->val);
        TreeNode *suc = getSuccessor(root, r->val);
        while (res.size() < k && pre && suc) {
            if (abs(pre->val - target) < abs(suc->val - target)) {
                res.push_back(pre->val);
                pre = getPredecessor(root, pre->val);
            } else {
                res.push_back(suc->val);
                suc = getSuccessor(root, suc->val);
            }
        }
        while (res.size() < k && pre) {
            res.push_back(pre->val);
            pre = getPredecessor(root, pre->val);
        }
        while (res.size() < k && suc) {
            res.push_back(suc->val);
            suc = getSuccessor(root, suc->val);
        }
        return res;
    }

private:
    int k;
    double mi, target;
    TreeNode *r;
    vector<int> res;
    void findCloset(TreeNode *root) {
        if (root == NULL)
            return;
        if (abs(root->val - target) < mi) {
            mi = abs(root->val - target);
            r = root;
        }
        if (root->val >= target)
            findCloset(root->left);
        else
            findCloset(root->right);
    }
    TreeNode *getPredecessor(TreeNode *root, int tar) {
        TreeNode *re = NULL;
        while (root != NULL) {
            if (root->val >= tar) {
                root = root->left;
            } else {
                re = root;
                root = root->right;
            }
        }
        return re;
    }
    TreeNode *getSuccessor(TreeNode *root, int tar) {
        TreeNode *re = NULL;
        while (root != NULL) {
            if (root->val <= tar) {
                root = root->right;
            } else {
                re = root;
                root = root->left;
            }
        }
        return re;
    }
};