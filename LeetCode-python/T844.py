class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        left, right = 0, 0
        S = list(s)
        while right < len(S):
            if S[right] != "#":
                S[left] = S[right]
                left += 1
            else: 
                left -= 1
                if left < 0:
                    left = 0
            
            right += 1
        temp = left
        left, right = 0, 0
        T = list(t)
        while right < len(T):
            if T[right] != "#":
                T[left] = T[right]
                left += 1
            else: 
                left -= 1
                if left < 0:
                    left = 0
            
            right += 1
        if S[0:temp] == T[0:left]:
            return True
        else: return False
