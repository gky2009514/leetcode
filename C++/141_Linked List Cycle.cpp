class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && slow != fast) {
            fast = fast->next;
            fast = fast == NULL ? fast : fast->next;
            slow = slow->next;
        }
        return slow == fast;
    }
};