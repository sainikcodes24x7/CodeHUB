import math
lst1 = [int(a) for a in input().split()]
lst2 = [int(b) for b in input().split()]
lst3 = [int(c) for c in input().split()]
lst4 = [int(d) for d in input().split()]
lst5 = [int(e) for e in input().split()]
lst = lst1 + lst2 + lst3 + lst4 + lst5
#print(lst)             Error checking and analysis line
k = lst.index(1) + 1
if k % 5 == 0:
    row = int(k / 5)
    col = 5
else:
    row = math.ceil(k / 5)
    col = (k % 5)
ans = abs(3 - row) + abs(3 - col)
#print(col, row)        Error checking and analysis line
print(ans)

