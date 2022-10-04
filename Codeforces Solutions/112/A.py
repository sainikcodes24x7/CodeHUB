str1 = input()
str2 = input()
str1 = str1.lower()
str2 = str2.lower()
if str1 < str2:
    print(-1)
elif str1 == str2:
    print(0)
elif str1 > str2:
    print(1)
