class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *now = head;
        while (now->next != NULL) {
            if (now->next->val == now->val)
                now->next = now->next->next;
            else
                now = now->next;
        }
        return head;
    }
};