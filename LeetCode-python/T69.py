###二分查找
class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x
        else: left, right = 1, x//2
        while left <= right:
            mid = left + (right - left) // 2
            if mid**2 <= x and x < (mid+1)**2:
                return mid
            elif mid**2 > x:
                right = mid -1
            else: left = mid + 1
