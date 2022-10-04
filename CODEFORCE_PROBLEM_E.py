n=int(input())
a=list(map(int,input().split()))
l,r=0,n-1
while l+1<n and a[l]<a[l+1]:
    l+=1
while r>=0 and a[r]<a[r-1]:
    r-=1
l=l+1
r=n-r
if l%2 or r%2:
    print('Alice')
else:
    print('Bob')
    
    
  # Problem solved by ashavijit for the issue you created
