class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *sorted = head, *now = head->next;
        head->next = NULL;
        while (now != NULL) {
            ListNode *tmp = now->next;
            if (now->val <= sorted->val) {
                now->next = sorted;
                sorted = now;
            }
            else {
                ListNode *pre = sorted, *pos = sorted->next;
                while (pos != NULL && pos->val < now->val) {
                    pre = pos;
                    pos = pos->next;
                }
                pre->next = now;
                now->next = pos;
            }
            now = tmp;
        }
        return sorted;
    }
};