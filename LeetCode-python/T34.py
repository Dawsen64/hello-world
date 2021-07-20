class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if target == nums[mid]:
                left, right = mid, mid
                while nums[left - 1] == target or nums[right + 1] == target:
                    if nums[left -1] == target:
                        left -= 1
                    if nums[right +1] == target:
                        right += 1
                
                return [left, right]
            elif target < nums[mid]:
                right = mid - 1
            elif target > nums[mid]:
                left = mid + 1
        
        return [-1, -1]
