class Solution:
    def recGen(self, nums, sol, lst):
        #print(nums)
        if not nums:
            sol.append(lst)
            return
        
        for i in range(len(nums)):
            #print("l:",nums)
            temp = nums.copy()
            n = temp.pop(i)
            tList = lst.copy()
            tList.append(n)
            self.recGen(temp, sol, tList)
            
            
    def permute(self, nums: List[int]) -> List[List[int]]:
        sol = []
        self.recGen(nums,sol,list())
        return sol