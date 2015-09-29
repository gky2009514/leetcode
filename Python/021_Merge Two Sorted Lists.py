class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head, pre = None, None
        while l1 is not None and l2 is not None:
            if l1.val <= l2.val:
                if head is None:
                    head = l1
                else:
                    pre.next = l1
                pre = l1
                l1 = l1.next
            else:
                if head is None:
                    head = l2
                else:
                    pre.next = l2
                pre = l2
                l2 = l2.next
        while l1 is not None:
            if head is None:
                head = l1
            else:
                pre.next = l1
            pre = l1
            l1 = l1.next
        while l2 is not None:
            if head is None:
                head = l2
            else:
                pre.next = l2
            pre = l2
            l2 = l2.next
        return head