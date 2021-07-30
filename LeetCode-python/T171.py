#每日一题
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        count = 0
        Length = len(columnTitle) - 1
        sum = 0
        for i in columnTitle:
            sum += (ord(i) - ord('A') + 1) * 26**(Length - count)
            count += 1
        return sum
