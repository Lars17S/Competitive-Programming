class Solution:
    def recGen(self, sol, maps, digits, i, s):
        if i == len(digits):
            sol.append(s)
            return
        
        for c in maps[int(digits[i])]:
            self.recGen(sol,maps,digits,i+1,s+c)
        
    
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        maps = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        sol = []
        self.recGen(sol,maps,digits,0,"")
        return sol
            