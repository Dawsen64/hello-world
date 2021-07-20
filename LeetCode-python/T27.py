class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        count = 0
        for i in nums:
            if i == val:
                count += 1
        if count == len(nums):
            return 0
        for i in range(len(nums) - count, len(nums)):
            if nums[i] != val:
                for j in range(0, len(nums) - count):
                    if nums[j] == val:
                        nums[j] = nums[i]
                        break

        print(nums)
        return len(nums) - count

x = Solution()
nums = [0,1,2,2,3,0,4,2]
k = 2
print(x.removeElement(nums, k))

##双指针

class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        left, right = 0, 0
        while right < len(nums):
            if nums[right] != val:
                nums[left] = nums[right]
                left += 1
                right += 1
            else:
                right += 1
        return left
