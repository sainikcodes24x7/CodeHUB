n = int(input())
count = 0
for i in range(0, n):
    instr = input()
    instr = [int(x) for x in instr.split()]
    k = instr.count(1)
    if k > 1:
        count = count + 1
print(count)
