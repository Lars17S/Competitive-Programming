class Solution:
    def rec_sol(self, tb, m, n):
        if m < 0 or n < 0:
            return 0
        
        if tb[m][n] != -1:
            return tb[m][n]
        
        if m == 0 and n == 0:
            tb[m][n] = 1
            return 1
        
        #tb[m-1][n] = self.rec_sol(tb, m - 1, n)
        #tb[m][n-1] = self.rec_sol(tb, m, n - 1)
        tb[m][n] = self.rec_sol(tb, m - 1, n) + self.rec_sol(tb, m, n - 1)
        #print("m:",m," | n:",n, " done")
        return tb[m][n]
    
    def uniquePaths(self, m: int, n: int) -> int:
        tb = [[-1] * n for i in range(m)]
        #sol = self.rec_sol(tb,m-1, n-1)
        #print(tb)
        return self.rec_sol(tb,m-1, n-1)
        # return math.comb(m+n-2, n-1) XD