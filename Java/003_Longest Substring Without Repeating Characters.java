package algorithm;

import java.util.*;

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public int lengthOfLongestSubstring(String s) {
		HashMap<Character, Byte> hm = new HashMap<Character, Byte>();
		hm.clear();
		int i = 0, j = 0;
		int res = 0;
		while (j < s.length()) {
			if (hm.get(s.charAt(j)) == null) {
				hm.put(s.charAt(j), (byte)0);
				j++;
				res = Math.max(res, j - i);
			}
			else {
				hm.remove(s.charAt(i));
				i++;
			}
		}
		return res;
	}
}

public class Test {
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.lengthOfLongestSubstring("abcabcbb"));
		System.out.println(s.lengthOfLongestSubstring("bbbbb"));
	}
}