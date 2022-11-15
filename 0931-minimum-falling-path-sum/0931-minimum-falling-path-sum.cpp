class Solution {
public:
     int dp[101][101];
    int nightfall(vector<vector<int>>& matrix,int i, int j)
    {
        if(i==matrix.size())
            return 0;
        if(j>=matrix.size()|| j<0)
            return 1e9;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int tot=INT_MAX;
        tot=min(tot,matrix[i][j]+nightfall(matrix,i+1,j-1));
        tot=min(tot,matrix[i][j]+nightfall(matrix,i+1,j+1));
        tot=min(tot,matrix[i][j]+nightfall(matrix,i+1,j));
        return dp[i][j]=tot;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
             ans=min(ans,nightfall(matrix,0,i));
        }
        return ans;
    }
};