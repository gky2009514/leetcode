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
	private int N;
	public String longestPalindrome(String s) {
		N = s.length();
		if (N == 0 || N == 1)
			return s;
		boolean[][] isPal = new boolean[N][N];
		int st = 0, ed = 0;
		for (int i = 0; i < N - 1; i++) {
			isPal[i][i] = true;
			if (s.charAt(i) == s.charAt(i + 1)) {
				isPal[i][i + 1] = true;
				st = i;
				ed = i + 2;
			}
		}
		isPal[N - 1][N - 1] = true;
		for (int j = 2; j < N; j++) {
			for (int i = 0; i < N - j; i++) {
				if (s.charAt(i) == s.charAt(i + j) && isPal[i + 1][i + j - 1]) {
					isPal[i][i + j] = true;
					st = i;
					ed = i + j + 1;
				}
			}
		}
		return s.substring(st, ed);
	}
}

public class Test {
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.longestPalindrome("abaac"));
		System.out.println("aab".substring(0, 3));
	}
}