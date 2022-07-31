class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)
            return 1;
        int a[n+1];
        a[0]=0;
        a[1]=1;
        a[2]=2;  //directly or 1step at a time
        //a[3]=4;  // 1+1+1 , 1+2, 2+1, 3
        for(int i=3;i<=n;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        return a[n];
    }
};