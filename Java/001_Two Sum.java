package algorithm;

import java.util.*;

class Solution {
    public int[] twoSum(int[] numbers, int target) {
    	int[] res = new int[2];
    	HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
    	for (int i = 0; i < numbers.length; i++)
    		hm.put(numbers[i], i);
    	for (int i = 0; i < numbers.length; i++) {
    		int left = target - numbers[i];
    		if (hm.get(left) != null && hm.get(left) > i) {
    			res[0] = i + 1;
    			res[1] = hm.get(left) + 1;
    			break;
    		}
    	}
    	return res;
    }
}

public class Test {
	public static void main(String[] args) {
		int[] numbers = {0, 4, 3, 0};
		Solution s = new Solution();
		int[] res = s.twoSum(numbers, 0);
		for (int i: res)
			System.out.println(i);
	}
}