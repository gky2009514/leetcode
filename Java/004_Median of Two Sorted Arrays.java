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
	private int N, M;
	private int[] A, B;
	private int findKth(int k, int ll, int lr, int rl, int rr) {
		if (ll > lr)
			return B[rl + k - 1];
		if (rl > rr)
			return A[ll + k - 1];
		if (k == 1)
			return Math.min(A[ll], B[rl]);
		int n = lr - ll + 1;
		int m = rr - rl + 1;
		int lpos, rpos;
		if (n >= m) {
			rpos = Math.min(k >> 1, m);
			lpos = k - rpos;
		}
		else {
			lpos = Math.min(k >> 1, n);
			rpos = k - lpos;
		}
		if (A[ll + lpos - 1] < B[rl + rpos - 1])
			return findKth(k - lpos, ll + lpos, lr, rl, rr);
		else if (A[ll + lpos - 1] > B[rl + rpos - 1])
			return findKth(k - rpos, ll, lr, rl + rpos, rr);
		else
			return A[ll + lpos - 1];
	}
	public double findMedianSortedArrays(int A[], int B[]) {
    	N = A.length;
    	M = B.length;
    	this.A = A;
    	this.B = B;
    	if (((N & 1) == 1 && (M & 1) == 1) || ((N & 1) == 0 && (M & 1) == 0))
    		return ((double)findKth((N + M) / 2, 0, N - 1, 0, M - 1) +
    				findKth((N + M) / 2 + 1, 0, N - 1, 0, M - 1)) / 2;
    	else
    		return (double)findKth((N + M) / 2 + 1, 0, N - 1, 0, M - 1);
    }
}

public class Test {
	public static void main(String[] args) {
		Solution s = new Solution();
		int[] A = {1, 2, 7, 9, 10};
		int[] B = {4, 5, 6, 8, 8, 8, 8, 8};
		System.out.println(s.findMedianSortedArrays(A, B));
	}
}