class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int sum, carry = 0;
        ListNode *head = new ListNode(-1);
        ListNode *now = head;
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            now->next = new ListNode(sum % 10);
            l1 = l1->next;
            l2 = l2->next;
            now = now->next;
        }
        while (l1 != NULL) {
            sum = l1->val + carry;
            carry = sum / 10;
            now->next = new ListNode(sum % 10);
            l1 = l1->next;
            now = now->next;
        }
        while (l2 != NULL) {
            sum = l2->val + carry;
            carry = sum / 10;
            now->next = new ListNode(sum % 10);
            l2 = l2->next;
            now = now->next;
        }
        if (carry)
            now->next = new ListNode(1);
        now = head->next;
        delete head;
        return now;
    }
};