# 滑动窗口
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        begin = 0
        c = Counter(t)
        distance = 0
        ans = len(s) + 1
        left, right = 0, 0
        # [left, right)
        dicts = {}
        while right < len(s):
            if c[s[right]] == 0:
                right += 1
                continue

            if dicts.get(s[right], 0) < c[s[right]]:
                if dicts.get(s[right], 0) == 0:
                    dicts[s[right]] = 0
                distance += 1

            dicts[s[right]] += 1
            right += 1

            while distance == len(t):
                # 移动左指针
                if right- left < ans:
                    ans = right - left
                    begin = left
                if c[s[left]] == 0:
                    left += 1
                    continue

                if dicts.get(s[left], 0) == c[s[left]]:
                    distance -= 1

                dicts[s[left]] -= 1
                left += 1
        if ans == len(s) + 1:
            return ""
        print("left", left)
        print("right", right)
        print("begin", begin)
        print("ans", ans)
        print(s[left - 1:left - 1: left - 1 + ans])
        return s[begin:begin + ans]
