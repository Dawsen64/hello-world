#!/usr/bin/env python
# coding=UTF-8

# @Author   : zqiusen@qq.comd
# @Time     : 2021/07/29 17:38
# @FileName : test.py
# @SoftWare : PyCharm

from collections import Counter



class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        matrix = [[0]*n for _ in range(n)]
        left, right, up, down = 0, n-1, 0, n-1
        count = 1
        while left <= right and up <= down and count <= n**2:
            for i in range(left, right+1):
                matrix[up][i] = count
                count += 1

            up += 1
            # if count > n**2:
            #     break
            for i in range(up, down+1):
                matrix[i][right] = count
                count += 1

            right -= 1
            # if count > n**2:
            #     break
            for i in range(right, left-1, -1):
                matrix[down][i] = count
                count += 1

            down -= 1
            # if count > n**2:
            #     break
            for i in range(down, up-1, -1):
                matrix[i][left] = count
                count += 1
            left += 1

        return matrix












