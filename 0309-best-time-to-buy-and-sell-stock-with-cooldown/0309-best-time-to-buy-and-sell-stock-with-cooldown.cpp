class Solution {
public:
    int helper(int index, int buy, vector<int>&prices,vector<vector<int>>&dp)
    {
        if(index>=prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        if(buy)
        {
            dp[index][buy]= max(-prices[index]+helper(index+1,0,prices,dp),0+helper(index+1,1,prices,dp));
        }
        else
        {
            dp[index][buy]= max(prices[index]+helper(index+2,1,prices,dp),0+helper(index+1,0,prices,dp));
        }
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};