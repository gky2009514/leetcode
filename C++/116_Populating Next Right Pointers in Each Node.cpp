class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode *now;
        while (root->left != NULL) {
            now = root;
            while (now != NULL) {
                now->left->next = now->right;
                if (now->next != NULL)
                    now->right->next = now->next->left;
                now = now->next;
            }
            root = root->left;
        }
    }
};