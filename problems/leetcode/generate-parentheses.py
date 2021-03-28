def recf(n, i, w, sol):
    if n == 0 and i == 0:
        sol.append(w)
    if n == 0 and i > 0:
        recf(n, i - 1, w + ")", sol)
    elif n > 0 and i > 0:
        recf(n - 1, i + 1, w + "(", sol)
        recf(n, i - 1, w + ")", sol)
    elif n > 0 and i == 0:
        recf(n - 1, i + 1, w + "(", sol)
        
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        sol = []
        recf(n, 0, "", sol)
        return sol