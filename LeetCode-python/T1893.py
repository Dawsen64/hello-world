class Solution:
        def isCovered(self, ranges: list[list[int]], left: int, right: int) -> bool:
            count = 0
            for i in range(left, right + 1):
                flag = 0
                for line in ranges:

                    if i in range(line[0],line[1]+1):
                        flag = 1
                    # print("flag", flag)
                if flag == 1:
                    count += 1
                # print(count)
            if count == right - left + 1:
                return True
            else:
                return False
 ###二分搜索
class Solution:
        def isCovered(self, ranges: list[list[int]], left: int, right: int) -> bool:
            count = 0
            for i in range(left, right + 1):
                flag = 0
                for line in ranges:
                    a,b = line[0], line[1]
                    while a <= b:
                        mid = a + (b-a) // 2
                        if mid == i:
                            flag = 1
                            break
                        elif mid < i:
                            a = mid +1
                        else: b = mid - 1

                   # if i in range(line[0],line[1]+1):
                    #    flag = 1
                    # print("flag", flag)
                if flag == 1:
                    count += 1
                # print(count)
            if count == right - left + 1:
                return True
            else:
                return False
            
