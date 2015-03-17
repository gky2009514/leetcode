class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fr = head;
        while (fr != NULL && n--)
            fr = fr->next;
        if (fr != NULL) {
            ListNode *se = head;
            while (fr->next != NULL) {
                fr = fr->next;
                se = se->next;
            }
            ListNode *tmp = se->next;
            se->next = tmp->next;
        }
        else if (n == 0)
            return head->next;
        return head;
    }
};