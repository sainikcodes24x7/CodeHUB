str1 = input()
c = 1
lst = sorted([x for x in str1])
for i in range(0, len(lst) - 1):
    if lst[i] != lst[i + 1]:
        c = c + 1
if c % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
