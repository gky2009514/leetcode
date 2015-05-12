class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        if not head:
            return False
        if head.next == head:
            return True
        second = head.next
        first = head
        while second and second != first:
            second = second.next
            if second:
                second = second.next
            first = first.next
        return second == first