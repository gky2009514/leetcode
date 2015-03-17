class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *now = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                now->next = l1;
                l1 = l1->next;
            }
            else {
                now->next = l2;
                l2 = l2->next;
            }
            now = now->next;
        }
        while (l1 != NULL) {
            now->next = l1;
            l1 = l1->next;
            now = now->next;
        }
        while (l2 != NULL) {
            now->next = l2;
            l2 = l2->next;
            now = now->next;
        }
        now = head->next;
        delete head;
        return now;
    }
};