class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not len(s):
            return 0
        last_pos = dict()
        p = 0
        max_val = -1
        for i in range(len(s)):
            if s[i] in last_pos.keys():
                if last_pos[s[i]] >= p:
                    max_val = max(max_val, (i - 1) - p + 1)
                    p = last_pos[s[i]] + 1
                else:
                    max_val = max(max_val, i - p + 1)
            else:
                max_val = max(max_val, i - p + 1)
            last_pos[s[i]] = i
        return max_val