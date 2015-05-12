class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode *pre = NULL, *now = head;
        while (now != NULL) {
            if (now->val != val) {
                if (pre == NULL)
                    head = now;
                pre = now;
            }
            else {
                if (pre != NULL)
                    pre->next = now->next;
            }
            now = now->next;
        }
        return pre == NULL ? NULL : head;
    }
};