from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # O(1) time 
        if k == len(nums):
            return nums
        # O(n log k)
        count = Counter(nums)
        return [x[0] for x in count.most_common(k)]