from bisect import bisect_left 

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sol = []
        nums.sort()
        last_dig = -99999999
        for i in range(len(nums) - 2):
            if nums[i] == last_dig:
                continue
            else:
                last_dig = nums[i]
                for j in range(i + 1, len(nums) - 1):
                    x = (nums[i] * -1) + (nums[j] * -1)
                    l = bisect_left(nums, x, j + 1)
                    if l != len(nums) and nums[l] == x:
                        if not sol:
                            sol.append([nums[i],nums[j],nums[l]])
                        else:
                            if not (sol[-1][0] == nums[i] and sol[-1][1] == nums[j] and sol[-1][2] == nums[l]):
                                sol.append([nums[i],nums[j],nums[l]])
        return sol