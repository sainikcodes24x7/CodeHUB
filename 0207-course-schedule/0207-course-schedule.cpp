class Solution {
public:
    bool dfs(int node, vector<vector<int>>& prerequisites, vector<int>&vis, vector<int>&prev,unordered_map<int,list<int>>&adj)
    {
        vis[node]=true;
        prev[node]=true;
        for(auto nbr:adj[node])
        {
            if(!vis[nbr])
            {
                 if(dfs(nbr,prerequisites,vis,prev,adj))
                {
                    return true;
                }
            }
            else if(prev[nbr]==true)
            {
                return true;
            }
        }
        prev[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        int n=numCourses;
        bool ans=true;
        vector<int>vis(n,0);
        vector<int>prev(n,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,prerequisites,vis,prev,adj))
                {
                    ans=false;
                }
            }
        }
        return ans;
        
    }
};