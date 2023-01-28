class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=amount+1;
        vector<int>dp(n,1000000);
        
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0)
                {
                    dp[i]=min(dp[i],(1+dp[i-coins[j]]));
                }
            }
        }
        return dp[n-1]>=1000000?-1:dp[n-1];
      
    }
};