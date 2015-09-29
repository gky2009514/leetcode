class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        pq = Queue.PriorityQueue(len(lists))
        for i in lists:
            if i is not None:
                pq.put_nowait((i.val, i))
        head, pre = None, None
        while not pq.empty():
            ft = pq.get_nowait()
            if head is None:
                head = ft[1]
            else:
                pre.next = ft[1]
            pre = ft[1]
            if ft[1].next is not None:
                pq.put_nowait((ft[1].next.val, ft[1].next))
        return head