class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *res = NULL, *tail = NULL;
        ListNode *fast;
        while (head != NULL) {
            if (head->next == NULL || head->next->val != head->val) {
                if (res == NULL)
                    res = head;
                else
                    tail->next = head;
                tail = head;
                head = head->next;
            }
            else {
                fast = head->next;
                while (fast != NULL && fast->val == head->val)
                    fast = fast->next;
                head = fast;
            }
        }
        if (tail != NULL)
            tail->next = NULL;
        return res;
    }
};