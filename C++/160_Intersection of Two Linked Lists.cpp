class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *taila, *tailb;
        int lena = get_len(headA, taila);
        int lenb = get_len(headB, tailb);
        if (taila != tailb)
            return NULL;
        ListNode *pre = lena > lenb ? headA : headB;
        int num = abs(lena - lenb);
        while (num--)
            pre = pre->next;
        ListNode *nt = lena > lenb ? headB : headA;
        while (pre != nt) {
            pre = pre->next;
            nt = nt->next;
        }
        return pre;
    }
private:
    int get_len(ListNode *head, ListNode *&tail) {
        if (NULL == head) {
            tail = NULL;
            return 0;
        }
        int len = 1;
        while (head->next) {
            head = head->next;
            len++;
        }
        tail = head;
        return len;
    }
};