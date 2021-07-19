class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        ans = right + 1
    
        while left <= right:
            mid = left + (right - left) //2
            if target > nums[mid]:
                left = mid + 1
            elif target <= nums[mid]:
                ans = mid
                right = mid - 1
        return ans   
