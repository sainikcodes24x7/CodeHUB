n = int(input())
lst = []
passcnt = 0
for i in range(0, n):
    x, y = [int(a) for a in input().split()]
    passcnt = passcnt - x + y
    lst.append(passcnt)
print(max(lst))
