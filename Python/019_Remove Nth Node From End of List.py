class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fast = head
        while fast is not None and n > 0:
            fast = fast.next
            n -= 1
        slow, pre = head, None
        while fast is not None:
            pre = slow
            slow = slow.next
            fast = fast.next
        if pre is None:
            return head.next
        pre.next = slow.next
        return head