class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        return sort(head);
    }
private:
    ListNode *sort(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head, *fast = head->next->next;
        while (fast != NULL) {
            fast = fast->next;
            fast = fast == NULL ? fast : fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *l = sort(head);
        ListNode *r = sort(fast);
        return merge(l, r);
    }
    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *head, *tail;
        if (a->val < b->val) {
            head = a;
            a = a->next;
        }
        else {
            head = b;
            b = b->next;
        }
        tail = head;
        while (a != NULL && b != NULL) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if (a != NULL)
            tail->next = a;
        else if (b != NULL)
            tail->next = b;
        else
            tail->next = NULL;
        return head;
    }
};