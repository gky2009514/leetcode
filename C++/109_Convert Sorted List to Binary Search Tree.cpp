class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL) {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *one = head, *pre;
        ListNode *two = head->next;
        while (two != NULL) {
            two = two->next;
            if (two != NULL)
                two = two->next;
            pre = one;
            one = one->next;
        }
        TreeNode *root = new TreeNode(one->val);
        pre->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(one->next);
        return root;
    }
};