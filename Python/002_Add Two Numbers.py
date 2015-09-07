class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head, carry = ListNode(-1), 0
        node = head
        while l1 and l2:
            tmp = l1.val + l2.val + carry
            carry = tmp / 10
            node.next = ListNode(tmp % 10)
            node = node.next
            l1, l2 = l1.next, l2.next
        while l1:
            tmp = l1.val + carry
            carry = tmp / 10
            node.next = ListNode(tmp % 10)
            node, l1 = node.next, l1.next
        while l2:
            tmp = l2.val + carry
            carry = tmp / 10
            node.next = ListNode(tmp % 10)
            node, l2 = node.next, l2.next
        if carry:
            node.next = ListNode(1)
        return head.next