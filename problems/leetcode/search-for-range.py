class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        i = bisect_left(nums, target)
        return [i, bisect_right(nums, target)-1] if i != len(nums) and nums[i] == target else [-1, -1]