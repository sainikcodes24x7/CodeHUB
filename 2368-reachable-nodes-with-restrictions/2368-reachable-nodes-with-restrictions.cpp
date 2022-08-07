class Solution {
public:
    //unordered_set<int>s;
    int solve(int node, int n, vector<int>adj[], vector<bool>&vis)
    {
        if(vis[node])
            return 0;
        int cnt=0;
        vis[node]=true;
       for(auto nbr:adj[node])
       {
           if(!vis[nbr])
           {
               cnt+=solve(nbr,n,adj,vis);
           }
       }
        return cnt+1;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        for(auto itr:edges)
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        vector<bool>vis(n,false);
        for(auto itr:restricted)
        {
            vis[itr]=true;
        }
        
        return solve(0,n,adj,vis);
    }
};