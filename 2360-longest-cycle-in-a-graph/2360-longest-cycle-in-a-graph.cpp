class Solution {
public:
    int mx=-1;
    void dfs(int node, vector<int>&vis, vector<int>&pvis, vector<int>&edges,int j)
    {
        if(pvis[node])
        {
            mx=max(mx,j-pvis[node]);
            return;
        }
        if(!vis[node])
        {
            pvis[node]=j;
            j++;
            vis[node]=1;
            if(edges[node]!=-1)
                dfs(edges[node],vis,pvis,edges,j);
        }
            pvis[node]=0;
        return;
    }
        
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0),pvis(n,0);
     mx=-1;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,vis,pvis,edges,1);
        }
        return mx;
    }
};