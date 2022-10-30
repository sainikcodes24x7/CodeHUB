class Solution {
public:
       int dp[47][47][47*47];
    int helper1(vector<vector<int>>& grid, int k, int r, int c, vector<vector<int>> &vis)
    {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || vis[r][c])return 1e6;
        if(dp[r][c][k] != -1)return dp[r][c][k];
        if(r==0 && c==0)return dp[r][c][k] = 0;
        
        
        
        if(grid[r][c]==1)
        {
            if(k>0)
            {
                k--;
            }
            else{
                return dp[r][c][k] = 1e6;
            }
        }
        
        
        
        vis[r][c]=1;
        
        int w1, w2, w3, w4;
        w1=w2=w3=w4=1e6;
        w1 = helper1(grid,k,r-1,c,vis);
        w2 = helper1(grid,k,r,c-1,vis);
        w3 = helper1(grid,k,r+1,c,vis);
        w4 = helper1(grid,k,r,c+1,vis);
        
        vis[r][c]=0;
        
        return dp[r][c][k] = 1+min({w1, w2, w3, w4});
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        memset(dp, -1, sizeof dp);
        vector<vector<int>> vis1((int)grid.size(), vector<int>((int)grid[0].size(), 0));
        int ans2 = helper1(grid, k, grid.size()-1, grid[0].size()-1, vis1);
        if(ans2>=1e6)return -1;
        return ans2;
    }
};