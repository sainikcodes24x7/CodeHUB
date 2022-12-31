class Solution {
public:
    int path(int i, int j, vector<vector<int>>& grid, int n, int m, int &c, int cnt)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==-1 or grid[i][j]==3)
        {
            return 0;
        }
        if(grid[i][j]==2)
        {
            if(cnt-1==c)
                return 1;
            return 0;
        }
        grid[i][j]=3;
        int up=path(i+1,j,grid,n,m,c,cnt+1);
        int down=path(i-1,j,grid,n,m,c,cnt+1);
        int left=path(i,j+1,grid,n,m,c,cnt+1);
        int right=path(i,j-1,grid,n,m,c,cnt+1);
        
        grid[i][j]=0;
        return up+down+left+right;
            
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int s,e;
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    s=i;
                    e=j;
                }
                if(grid[i][j]==0)
                    c++;
            }
        }
        return path(s,e,grid,n,m,c,0);
    }
};