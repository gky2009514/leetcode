class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode *slow = head, *fast = head->next->next;
        while (fast != NULL) {
            fast = fast->next;
            fast = fast == NULL ? fast : fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *ftail = fast;
        slow = fast;
        fast = fast->next;
        while (fast) {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        ftail->next = NULL;
        while (slow != NULL) {
            ListNode *tmp = slow->next;
            slow->next = head->next;
            head->next = slow;
            head = slow->next;
            slow = tmp;
        }
    }
};