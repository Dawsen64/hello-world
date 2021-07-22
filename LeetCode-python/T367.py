###牛顿迭代
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        guess = num
        while guess**2 - num >= 0.00001:
            guess = (guess + num / guess) / 2
        if int(guess)**2 == num:
            return True
        else: return False
