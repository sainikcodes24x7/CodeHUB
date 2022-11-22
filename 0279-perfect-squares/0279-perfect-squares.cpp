class Solution {
public:
    int numSquares(int n) {
        if(n<=1)
            return 1;
        int dp[n+1];
        
        //int dp[n+1];
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=i;
        }
        for(int i=2;i<=n;i++)
        {
            int minm=INT_MAX;
            for(int j=1;j<=sqrt(i);j++)
            {
                
                minm=min(minm,dp[i-j*j]);
                
                
            }
           dp[i]=1+minm; 
        }
        return dp[n];
    }
};