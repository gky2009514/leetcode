class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || n - m <= 0)
            return head;
        ListNode *now = head, *before = NULL;
        int num = m;
        while (--num) {
            before = now;
            now = now->next;
        }
        num = n - m;
        ListNode *ed = now;
        ListNode *nt = now->next, *after = nt->next;
        while (num--) {
            nt->next = now;
            now = nt;
            nt = after;
            after = nt == NULL ? nt : nt->next;
        }
        ed->next = nt;
        if (before != NULL) {
            before->next = now;
            return head;
        }
        else
            return now;
    }
};