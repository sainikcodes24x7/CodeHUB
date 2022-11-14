class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return 0;
        dp[0][0]=1;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if((!row && !col) || (grid[row][col]==1))
                    continue;
                //else
                   // dp[row][col]=dp[row][col]+dp[row-1][col]+dp[row][col-1];
                int top=0,bottom=0;
                if(row>0)
                    top=dp[row-1][col];
                if(col>0)
                    bottom=dp[row][col-1];
                dp[row][col]=top+bottom;
            }
        }
        return dp[n-1][m-1];
    }
};