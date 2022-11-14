class Solution {
public:
    void dfs(int node, vector<int>adj[], vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
               dfs(it,adj,vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                count++;
            }
        }
        return n-count;
    }
};