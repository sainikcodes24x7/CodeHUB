class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int dp[3][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=2;i++)
        {
            int maxdiff=INT_MIN;
            for(int j=1;j<n;j++)
                {
                    maxdiff=max(maxdiff,dp[i-1][j-1]-arr[j-1]);
                    dp[i][j]=max(maxdiff+arr[j],dp[i][j-1]);
                }
        }
        return dp[2][n-1];
    }
};