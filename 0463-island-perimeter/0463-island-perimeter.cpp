class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=4;
                    //cout<<i<<","<<j<<endl;
                    if(i>0 and grid[i-1][j]==1)
                    {
                        ans-=2;
                        //cout<<i<<","<<j<<" ";
                    }
                    if(j>0 and grid[i][j-1]==1)
                    {
                        ans-=2;
                      //  cout<<i<<","<<j<<" ";
                    }
                }
            }
        }
        return ans;
    }
};