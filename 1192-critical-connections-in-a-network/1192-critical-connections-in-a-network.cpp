class Solution {
public:
    void dfs(int node, int p, vector<int>adj[], int v1[], int v2[], vector<int>&v, vector<vector<int>>&ans, int &cnt)
    {
        v1[node]=cnt;
        v2[node]=cnt;
        v[node]=1;
        cnt++;
        for(auto nbr:adj[node])
        {
            if(nbr==p)
                continue;
            if(v[nbr])
                v1[node]=min(v1[node],v1[nbr]);
            else
            {
                dfs(nbr,node,adj,v1,v2,v,ans,cnt);
                v1[node]=min(v1[node],v1[nbr]);
                if(v1[nbr]>v2[node])
                    ans.push_back({nbr,node});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>v(n,0);
        int cnt=1;
        int v1[n], v2[n];
        vector<vector<int>>ans;
        dfs(0,-1,adj,v1,v2,v,ans,cnt);
        return ans;
    }
};