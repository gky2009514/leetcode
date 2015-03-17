class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode *first = NULL, *pre = NULL;
        while (root != NULL) {
            TreeLinkNode *now = root;
            while (now != NULL) {
                if (now->left != NULL) {
                    if (first == NULL)
                        first = pre = now->left;
                    else
                        pre->next = now->left;
                    pre = now->left;
                }
                if (now->right != NULL) {
                    if (first == NULL)
                        first = pre = now->right;
                    else
                        pre->next = now->right;
                    pre = now->right;
                }
                now = now->next;
            }
            root = first;
            first = pre = NULL;
        }
    }
};