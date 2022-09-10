class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>dp(2*k+1, INT_MIN);
        dp[0]=0;
        for(int i=0;i<prices.size();i++)
        {
            for(int j=0;j+2<=2*k;j+=2)
            {
                dp[j+1]=max(dp[j+1],dp[j]-prices[i]);
                dp[j+2]=max(dp[j+2],dp[j+1]+prices[i]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};