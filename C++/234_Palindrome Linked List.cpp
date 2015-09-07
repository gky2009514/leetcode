class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head, *fast = head->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : fast;
        }
        before = head;
        return check(slow);
    }

private:
    ListNode *before;

    bool check(ListNode* now) {
        if (now == NULL)
            return true;
        if (!check(now->next))
            return false;
        if (before->val != now->val)
            return false;
        before = before->next;
        return true;
    }
};