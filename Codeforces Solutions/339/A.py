sumstr = input()
if len(sumstr) == 1:
    k = int(sumstr)
    print(k)
else:
    lst = sorted([str(i) for i in sumstr.split("+")])
    sumfinal = ""
    for a in range(0, len(lst) - 1):
        sumfinal = sumfinal + lst[a] + "+"
    sumfinal = sumfinal + lst[len(lst) - 1]
    print(sumfinal)