n = int(input())
for i in range(0, n):
    wrd = str(input())
    if len(wrd) > 10:
        num = str(len(wrd) - 2)
        result = wrd[0]+num+wrd[len(wrd) - 1]
        print(result)
    else:
        print(wrd)