class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void dfs(vector<vector<int>>& heights, int i, int j,int prev,vector<vector<int>>&ocean)
    {
        if(i<0 || i==heights.size() || j<0 || j==heights[0].size() || heights[i][j]<prev || ocean[i][j]==1)
            return;
        ocean[i][j]=1;
        for(int K=0;K<4;K++)
        {
            dfs(heights,i+dx[K],j+dy[K],heights[i][j],ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans;
        
        if(n==0)
            return ans;
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    dfs(heights,0,j,INT_MIN,pacific);
                    dfs(heights,i,0,INT_MIN,pacific);
                }
                
                if(i==n-1 || j==m-1)
                {
                    
                    dfs(heights,n-1,j,INT_MIN,atlantic);
                    dfs(heights,i,m-1,INT_MIN,atlantic);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]==1 and atlantic[i][j]==1)
                    ans.push_back({i,j});
                
            }
        }   
       return ans; 
    }
};