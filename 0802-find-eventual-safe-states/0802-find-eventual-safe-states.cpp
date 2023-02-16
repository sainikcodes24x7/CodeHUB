class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& vis, vector<int>& dfsVis)
    {
        if(dfsVis[src])return true;
        if(vis[src])return false;
        vis[src] = 1;
        dfsVis[src] = 1;
        for(auto &x: graph[src])
        {
            if(dfs(x,graph,vis,dfsVis))return true;
        }
        dfsVis[src] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = size(graph);
        vector<int> res;
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        for(int i = 0; i < n; i++)
        {
            if(!dfs(i,graph,vis,dfsVis))res.push_back(i);
        }
        return res;
    }
};