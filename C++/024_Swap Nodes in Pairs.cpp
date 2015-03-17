class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *l = head, *r, *pre = NULL;
        ListNode *res = head->next;
        while (l != NULL) {
            if (l->next != NULL) {
                r = l->next;
                l->next = r->next;
                r->next = l;
                if (pre != NULL)
                    pre->next = r;
                pre = l;
                l = l->next;
            }
            else
                return res;
        }
        return res;
    }
};