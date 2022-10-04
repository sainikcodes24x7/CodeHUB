n = int(input())
count = 0
for i in range(0, n):
    k = input()
    if k[1] == "+":
        count = count + 1
    else:
        count = count - 1
print(count)