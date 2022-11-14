class Solution {
public:
    int minsum(int i, int j,vector<vector<int>>& grid,int n, int m, vector<vector<int>>&dp)
    {
        if(i==n || j==m)
            return INT_MAX;
        
        if(i==n-1 and j==m-1)
            return grid[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=minsum(i+1,j,grid,n,m,dp);
        int up=minsum(i,j+1,grid,n,m,dp);
        return dp[i][j]=grid[i][j]+min(down,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return minsum(0,0,grid,n,m,dp);
    }
};