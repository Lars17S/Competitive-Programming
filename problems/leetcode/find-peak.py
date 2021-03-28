class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        if nums[0] > nums[1]:
            return 0
        if nums[-1] > nums[-2]:
            return len(nums) - 1
        p = 1
        q = len(nums) - 2
        r = (p + q) / 2
        while q > p:
            r = int((p + q) / 2)
            m = max(max(nums[r - 1], nums[r]), nums[r + 1])
            if nums[r] == m:
                p = r
                break
            if nums[r - 1] == m:
                q = r - 1
                continue
            if nums[r + 1] == m:
                p = r + 1
        return p
        