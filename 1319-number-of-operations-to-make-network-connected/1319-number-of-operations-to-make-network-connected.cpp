class Solution {
public:
    void dfs(int node, vector<bool>&vis, unordered_map<int,vector<int>>&adj)
    {
        vis[node]=true;
        for(auto nbr:adj[node])
        {
            if(!vis[nbr])
                dfs(nbr,vis,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz=connections.size();
        if(sz<n-1)
            return -1;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<sz;i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        int comp=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                comp++;
            }
        }
        return comp-1;
    }
};