class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int dfs(int i, int j,vector<vector<char>>& grid)
    {
        if(i<0 ||i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]=='0')
        {
            return 0;
        }
        grid[i][j]='0';
        for(int x=0;x<4;x++)
        {
            dfs(i+dx[x],j+dy[x],grid);
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int num=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    num+=dfs(i,j,grid);
                }
            }
        }
        return num;
    }
};