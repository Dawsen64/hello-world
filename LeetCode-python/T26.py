##双指针
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        first, second = 0, 1
        while second < len(nums):
            if nums[first] != nums[second]:
                first += 1
                nums[first] = nums[second]
            second += 1
        return first + 1
