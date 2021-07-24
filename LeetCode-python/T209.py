class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left, right = 0, 0
        total = nums[0]
        res = len(nums) + 1
        while right < len(nums):
            if total >= target:
                while total - nums[left] >= target:
                    #if total - nums[left] >= target:
                        total -= nums[left]
                        left += 1
                res = min(res, right - left + 1)
                left += 1
                right += 1
                if right < len(nums):
                    total = total - nums[left - 1] + nums[right]
            else:
                right += 1
                if right < len(nums):
                    total += nums[right]
        if res < len(nums) + 1:
            return res
        else: return 0
