class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # They have the same letters and each one of them are in the same quantity 
        # Las mismas letras en la misma cantidad
        # Same string length
        # Same letters in the same quantity each one
        if len(strs) == 1:
            return [strs]
        sol_dict = dict()
        for s in strs:
            srt = "".join(sorted(s))
            if srt not in sol_dict:
                sol_dict[srt] = []
            sol_dict[srt].append(s)
        return sol_dict.values()