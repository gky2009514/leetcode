class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && slow != fast) {
            fast = fast->next;
            fast = fast == NULL ? fast : fast->next;
            slow = slow->next;
        }
        if (fast == NULL)
            return NULL;
        fast = fast->next;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};