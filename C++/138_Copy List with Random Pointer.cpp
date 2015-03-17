class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode *now = head, *next;
        RandomListNode *nd;
        while (now != NULL) {
            next = now->next;
            nd = new RandomListNode(now->label);
            now->next = nd;
            nd->next = next;
            now = next;
        }
        now = head;
        while (now != NULL) {
            next = now->next->next;
            nd = now->next;
            nd->random = now->random == NULL ? NULL : now->random->next;
            now = next;
        }
        RandomListNode *pre = NULL, *res = NULL;
        now = head;
        while (now != NULL) {
            next = now->next->next;
            if (res == NULL)
                res = now->next;
            else
                pre->next = now->next;
            pre = now->next;
            now->next = next;
            now = next;
        }
        pre->next = NULL;
        return res;
    }
};