class Solution {
public:
    bool vis[201][201];
    bool isvalid(int i, int j, int n, int m)
    {
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==true)
            return false;
        return true;
    }
    int trapRainWater(vector<vector<int>>& grid) {
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        int n=grid.size();
        int m=grid[0].size();
        memset(vis,false,sizeof(vis));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0|| j==m-1)
                {
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        int water=0;
        int maxht=INT_MIN;
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int height=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            maxht=max(maxht,height);
            for(int i=0;i<4;i++)
            {
                int p=x+dx[i];
                int q=y+dy[i];
                
                if(isvalid(p,q,n,m))
                {
                    water+=max(0,maxht-grid[p][q]);
                    vis[p][q]=true;
                    pq.push({grid[p][q],{p,q}});
                }
            }
        }
        return water;
    }
};