n = int(input())
stones = str(input())
cnt = 0
for i in range(0, n - 1):
    if stones[i] == stones[i + 1]:
        cnt = cnt + 1
print(cnt)
