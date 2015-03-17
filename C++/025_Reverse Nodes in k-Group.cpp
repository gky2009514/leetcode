class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1 || head == NULL || head->next == NULL)
            return head;
        ListNode *nhead = head, *ntail = head, *ptail = NULL;
        head = NULL;
        int num;
        while (ntail != NULL) {
            num = k;
            while (--num)
                ntail = ntail == NULL ? ntail : ntail->next;
            if (ntail == NULL)
                break;
            ListNode *tmp = ntail->next;
            ntail->next = NULL;
            reverse(nhead, ntail);
            if (head == NULL)
                head = nhead;
            else
                ptail->next = nhead;
            ptail = ntail;
            nhead = ntail = tmp;
        }
        if (ptail != NULL)
            ptail->next = nhead;
        return head == NULL ? nhead : head;
    }
private:
    void reverse(ListNode *&head, ListNode *&tail) {
        ListNode *pre, *now, *next;
        pre = head, now = head->next;
        while (now != NULL) {
            next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        tail = head;
        head = pre;
    }
};