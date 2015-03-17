class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        int num = 0;
        ListNode *slow = head;
        while (slow != NULL) {
            slow = slow->next;
            num++;
        }
        k %= num;
        if (k == 0)
            return head;
        ListNode *fast = head;
        while (k--)
            fast = fast->next;
        slow = head;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        ListNode *res = slow->next;
        slow->next = NULL;
        return res;
    }
};