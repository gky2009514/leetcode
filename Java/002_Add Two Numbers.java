package algorithm;

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		if (l1 == null || l2 == null)
			return l1 == null ? l2 : l1;
		int sum = l1.val + l2.val;
		int carry = sum / 10;
		ListNode head = new ListNode(sum % 10);
		ListNode now, pre = head;
		l1 = l1.next;
		l2 = l2.next;
		while (l1 != null && l2 != null) {
			sum = l1.val + l2.val + carry;
			carry = sum / 10;
			now = new ListNode(sum % 10);
			pre.next = now;
			pre = now;
			l1 = l1.next;
			l2 = l2.next;
		}
		while (l1 != null) {
			sum = l1.val + carry;
			carry = sum / 10;
			now = new ListNode(sum % 10);
			pre.next = now;
			pre = now;
			l1 = l1.next;
		}
		while (l2 != null) {
			sum = l2.val + carry;
			carry = sum / 10;
			now = new ListNode(sum % 10);
			pre.next = now;
			pre = now;
			l2 = l2.next;
		}
		if (carry > 0) {
			now = new ListNode(carry);
			pre.next = now;
		}
		return head;
    }
}

public class Test {
	public static void main(String[] args) {
		Solution s = new Solution();
		ListNode[] a = new ListNode[4];
		ListNode[] b = new ListNode[3];
		a[0] = new ListNode(1);
//		a[1] = new ListNode(4);
//		a[2] = new ListNode(5);
//		a[3] = new ListNode(9);
//		a[0].next = a[1];
//		a[1].next = a[2];
//		a[2].next = a[3];
		b[0] = new ListNode(9);
		b[1] = new ListNode(9);
//		b[2] = new ListNode(4);
		b[0].next = b[1];
//		b[1].next = b[2];
		ListNode h = s.addTwoNumbers(a[0], b[0]);
		while (h != null) {
			System.out.println(h.val);
			h = h.next;
		}
	}
}