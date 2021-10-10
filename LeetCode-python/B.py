n, m = input().split()
n=int(n)
m=int(m)

if n%2 == 1 : # 行列有奇数就是yes
    print("YES")
    for i in range(1, n+1):
        if i%2 == 1:
            for j in range(1, m+1):
                if (i == 1 and j == 1) or (i == n and j == m):
                    pass
                else:
                    print(i,j)
        else:
            for j in range(m, 0, -1):
                if (i == 1 and j == 1) or (i == n and j == m):
                    pass
                else:
                    print(i,j)
elif m%2 == 1:
    print("YES")
    for i in range(1, m+1):
        if i%2 == 1:
            for j in range(1, n+1):
                if (i == 1 and j == 1) or (i == m and j == n):
                    pass
                else:
                    print(j,i)
        else:
            for j in range(n, 0, -1):
                if (i == 1 and j == 1) or (i == m and j == n):
                    pass
                else:
                    print(j,i)
else: print("NO")