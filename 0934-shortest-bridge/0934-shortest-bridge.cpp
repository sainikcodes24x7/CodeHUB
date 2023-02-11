class Solution {
public:
    queue<pair<int,int>>q;
    void dfs(vector<vector<int>>&grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==2 || grid[i][j]==0)
            return;
        grid[i][j]=2;
        q.push({i,j});
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int bfs(vector<vector<int>>&grid)
    {
        int dist=0;
        int mindist=INT_MAX;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto top=q.front();
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int x=top.first+dir[i][0];
                    int y=top.second+dir[i][1];
                    
                    if(x>=0 and y>=0 and x<grid.size() and y<grid[0].size() and grid[x][y]==1)
                    {
                        mindist=min(mindist,dist);
                    }
                    else if(x>=0 and y>=0 and x<grid.size() and y<grid[0].size() and grid[x][y]==0)
                    {
                        q.push({x,y});
                        grid[x][y]=2;
                    }
                }
            }
            dist++;
        }
        return mindist;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag=false;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 and !flag)
                {
                    dfs(grid,i,j);
                    q.push({i,j});
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        return bfs(grid);
    }
};