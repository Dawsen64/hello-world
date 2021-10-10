line = int(input())
grades = []
for i in range(line):
    grade = input()
    A,B,C = 0,0,0
    for j in range(len(grade)):
        k = 0
        if grade[j] == '+':
            A = int(grade[:j])
            B = int(grade[j+1:])
        
    grades.append(A+B*20)
for i in grades:
    print(i)