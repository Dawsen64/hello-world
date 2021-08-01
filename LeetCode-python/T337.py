from collections import Counter
class Solution:
    def kWeakestRows(self, mat: list[list[int]], k: int) -> list[int]:
        count = 0
        dicts = {}
        res = []
        for i in mat:
            c = Counter(i)
            # print(c[1])
            dicts[count] = c[1]
            count += 1
        count: int = 0
        # print(dicts)
        while count < k:
            ans = 200
            for i in range(0,len(mat)):
                if dicts[i] < ans:
                    ans = dicts[i]
                    j = i
            dicts[j] = 200
            res += [j]
            count += 1
        # print("res:", res)
        return res
   ##大佬写法
   sorted(range(len(mat)),key=lambda x:-bisect.bisect_right(mat[x][::-1],0))[:k]
   #或
   return sorted(range(len(mat)), key = lambda x: sum(mat[x]))[:k]
