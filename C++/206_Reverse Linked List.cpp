class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre = NULL, *now = head, *next = head->next;
        while (now != NULL) {
            now->next = pre;
            pre = now;
            now = next;
            next = now == NULL ? NULL : now->next;
        }
        return pre;
    }
};