class Solution {
public:
    int helper(int amount,vector<int>&coins, int idx, vector<vector<int>>&dp)
    {
        if(idx<0 || amount<0)
            return 0;
        if(amount==0)
            return 1;
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];
         return dp[idx][amount]=helper(amount-coins[idx],coins,idx,dp)+helper(amount,coins,idx-1,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(301,vector<int>(5001,-1));
        int n=coins.size();
        return helper(amount,coins,n-1,dp);
    }
};