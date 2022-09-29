class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        diffTuples = sorted((abs(x - num), num) for num in arr)
        return sorted(map(lambda x: x[1], diffTuples[:k])) #prefer the smaller number for same diff.
        