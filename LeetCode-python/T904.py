##假的双指针
class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        left, right = 0, 0
        res = 0
        total = 0
        while right < len(fruits):

            if fruits[right] not in fruits[left:right] and total < 2:
                total += 1
            right += 1
            # if fruits[right] in fruits[left:right]:
            #     right += 1
            if right == len(fruits):
                break
            if total == 2 and fruits[right] not in fruits[left:right]:
                res = max(res, right - left)
                left = right - 1
                total = 0
                while fruits[left - 1] == fruits[right - 1]:
                    left -= 1
                right = left

        res = max(res, right - left)
        return res
