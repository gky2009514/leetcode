class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL, *pre, *now;
        while (!pq.empty())
            pq.pop();
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }
        while (!pq.empty()) {
            now = pq.top();
            pq.pop();
            if (head == NULL)
                head = now;
            else
                pre->next = now;
            if (now->next != NULL)
                pq.push(now->next);
            pre = now;
        }
        return head;
    }
private:
    struct cmp {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
};