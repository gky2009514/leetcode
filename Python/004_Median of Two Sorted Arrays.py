class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n, m = len(nums1), len(nums2)
        if n == 0 and m == 0:
            return 0
        if (n + m) % 2 == 1:
            return self._findKth((n + m + 1) / 2, nums1, nums2)
        else:
            return (self._findKth((n + m) / 2, nums1, nums2) +
                    self._findKth((n + m) / 2 + 1, nums1, nums2)) / 2.0

    def _findKth(self, k, nums1, nums2):
        n, m = len(nums1), len(nums2)
        if n > m:
            return self._findKth(k, nums2, nums1)
        if n == 0:
            return nums2[k - 1]
        if k == 1:
            return min(nums1[0], nums2[0])
        l = min(n, k >> 1)
        r = k - l
        if nums1[l - 1] == nums2[r - 1]:
            return nums1[l - 1]
        elif nums1[l - 1] < nums2[r - 1]:
            return self._findKth(k - l, nums1[l:], nums2[0:r])
        else:
            return self._findKth(k - r, nums1[0:l], nums2[r:])