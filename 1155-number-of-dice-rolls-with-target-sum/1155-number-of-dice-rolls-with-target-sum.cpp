class Solution {
public:
    int mod=pow(10,9)+7;
    int solve(int n, int k, int target, vector<vector<int>>&dp)
    {
        if(n<0 || target<0)
            return 0;
        if(n==0)
            return target==0;
        if(dp[target][n]!=-1)
            return dp[target][n];
        int val=0;
        for(int i=1;i<=k;i++)
        {
            val=((val%mod)+solve(n-1,k,target-i,dp))%mod;
        }
        dp[target][n]=val%mod;
        return dp[target][n];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        return solve(n,k,target,dp)%mod;
    }
};