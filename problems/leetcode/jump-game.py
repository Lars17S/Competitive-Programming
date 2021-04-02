class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i = 0
        aj = nums[i]
        while i <= aj + i - 1 < len(nums) - 1:
            i = i + 1
            aj = aj - 1
            aj = max(nums[i], aj)
        return aj + i >= len(nums) - 1 