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

    ###二分查找，太妙了
    class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]
        #先找左边界
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if target == nums[mid]:
                right = mid -1
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1
        res = left
        #找右边界
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if target == nums[mid]:
                left = mid + 1
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1
        if res <= right:
            return [res, right]
        else: return [-1, -1]
