class Solution {
public:
    /*int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    */
    void maxIsland(vector<vector<int>>& grid,int m,int n,int i, int j, int& currarea)
    {
        if(i<0 || i>=m || j<0 || j>=n||grid[i][j]==0)
            return;
        
        currarea++;
        grid[i][j]=0;
        
        
        
        maxIsland(grid,m,n,i-1,j,currarea);
        maxIsland(grid,m,n,i+1,j,currarea);
        maxIsland(grid,m,n,i,j-1,currarea);
        maxIsland(grid,m,n,i,j+1,currarea);
        
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int currarea=0;
        int maxarea=0;
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;
                currarea=0;
                maxIsland(grid,m,n,i,j,currarea);
                maxarea=max(maxarea,currarea);
            }
        }
        return maxarea;
    }
};