class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *hl = NULL, *hr = NULL;
        ListNode *l = NULL, *r = NULL;
        ListNode *now = head;
        while (now != NULL) {
            if (now->val < x) {
                if (hl == NULL)
                    hl = l = now;
                else {
                    l->next = now;
                    l = l->next;
                }
            }
            else {
                if (hr == NULL)
                    hr = r = now;
                else {
                    r->next = now;
                    r = r->next;
                }
            }
            now = now->next;
        }
        if (r != NULL)
            r->next = NULL;
        if (hl != NULL) {
            l->next = hr;
            return hl;
        }
        else
            return hr;
    }
};