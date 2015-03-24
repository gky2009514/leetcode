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
	public String convert(String s, int nRows) {
		if (nRows == 1)
			return s;
		StringBuilder sb = new StringBuilder();
		int total = (nRows << 1) - 2;
		for (int i = 0; i < s.length(); i += total)
			sb.append(s.charAt(i));
		for (int i = 1; i < nRows - 1; i++) {
			int next = total - (i << 1);
			for (int j = i; j < s.length(); j += total) {
				sb.append(s.charAt(j));
				if (j + next < s.length())
					sb.append(s.charAt(j + next));
			}
		}
		for (int i = nRows - 1; i < s.length(); i += total)
			sb.append(s.charAt(i));
		return new String(sb);
	}
}

public class Test {
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.convert("PAYPALISHIRING", 3));
	}
}