class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=amount+1;
        vector<int>dp(n);
        for(int i=0;i<n;i++)
        {
            dp[i]=1000000;
        }
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0)
                {
                    dp[i]=min(dp[i],(1+dp[i-coins[j]]));
                }
            }
        }
        if(dp[n-1]>=1000000)
            return -1;
        else
        return dp[n-1];
    }
};