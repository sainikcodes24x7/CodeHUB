w = int(input())
if 0 <= w <= 100:
    if w == 2:
        print("NO")
    elif w % 2 == 0:
        print("YES")
    elif w % 2 != 0:
        print("NO")
else:
    quit()

