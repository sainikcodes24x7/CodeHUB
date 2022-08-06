class Solution {
public:
    vector<vector<int>>res;
    void dfs(int node, int parent, vector<bool>&vis, vector<int>&time, vector<int>&low, int cnt, vector<vector<int>>&adj)
    {
        vis[node]=true;
        time[node]=cnt;
        low[node]=cnt;
        cnt++;
        
        for(auto nbr:adj[node])
        {
            if(nbr==parent)
                continue;
            if(!vis[nbr])
                dfs(nbr,node,vis,time,low,cnt,adj);
            low[node]=min(low[node],low[nbr]);
            if(low[nbr]>time[node])
            {
                res.push_back({node,nbr});
            }
            else{
                low[node]=min(low[node],time[nbr]);
            }
                
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool>vis(n,false);
        vector<int>time(n,-1);
        vector<int>low(n,-1);
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,-1,vis,time,low,cnt,adj);
        }
        return res;
    }
};