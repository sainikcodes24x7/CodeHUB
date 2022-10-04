x,y = [int(x) for x in input().split()]
lst = []
scores = input()
scores = [int(i) for i in scores.split()]
#print(scores)
m = max(scores)
count = 0
#print(m)
if m == 0:
    print(0)
elif m > 0:
    if scores[y - 1] > 0:
        for c in scores:
            if c >= scores[y - 1]:
                count = count + 1
        print(count)
    elif scores[y - 1] == 0:
        for c in scores:
            if c > scores[y - 1]:
                count = count + 1
        print(count)
        
