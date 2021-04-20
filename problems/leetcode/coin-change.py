class Solution:
    def recSol(self, coins, dp, i, am):
        if (i, am) in dp.keys():
            return dp[(i, am)]
        
        if i == 0:
            dp[(i, am)] = int(am / coins[i]) if am % coins[i] == 0 else 100
            return dp[(i, am)]
            
        dp[(i, am)] = min(1 + self.recSol(coins, dp, i, am - coins[i]), self.recSol(coins, dp, i - 1, am)) if am - coins[i] >= 0 else self.recSol(coins, dp, i - 1, am)
        return dp[(i, am)]
    
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort()
        dp = {}
        sol = self.recSol(coins, dp, len(coins) - 1, amount)
        return sol if sol < 100 else -1