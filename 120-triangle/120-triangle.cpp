class Solution {
public:
    int helper(vector<vector<int>>& triangle,int dp[201][201], int idx, int pos, int n )
    {
        if(idx==n || pos==n)
            return 0;
        if(dp[idx][pos]!=-1)
            return dp[idx][pos];
        dp[idx][pos]=triangle[idx][pos]+min(helper(triangle,dp,idx+1,pos,n),helper(triangle,dp,idx+1,pos+1,n));
        return dp[idx][pos];
            
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[201][201];
        int n=triangle.size();
        memset(dp,-1,sizeof(dp));
        return helper(triangle,dp,0,0,n);
    }
};