class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k==0 or n==0)
            return 0;
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++)
        {
            int maxdiff=INT_MIN;
            for(int j=1;j<n;j++)
            {
                maxdiff=max(maxdiff,dp[i-1][j-1]-prices[j-1]);
                dp[i][j]=max(prices[j]+maxdiff,dp[i][j-1]);
            }
        }
        return dp[k][n-1];
    }
};