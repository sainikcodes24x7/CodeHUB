class Solution {
public:
    void dfs1(vector<int>adj[],vector<int>&ans,vector<int>&child,vector<int>&visited,int root, int length)
    {
        visited[root]=1;
        ans[0]+=length;
        length++;
        for(auto &nbr:adj[root])
        {
            if(visited[nbr])
                continue;
            dfs1(adj,ans,child,visited,nbr,length);
            child[root]+=child[nbr];
                
        }
        child[root]+=1;
    }
    void dfs2(vector<int>adj[],vector<int>&ans,vector<int>&child,vector<int>&visited,int root, int length)
    {
        visited[root]=1;
        for(auto &nbr:adj[root])
        {
            if(visited[nbr])
                continue;
            ans[nbr]=ans[root]-child[nbr]+length-child[nbr];
            dfs2(adj,ans,child,visited,nbr,length);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>ans(n),child(n),visited(n);
        dfs1(adj,ans,child,visited,0,0);
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }
        dfs2(adj,ans,child,visited,0,n);
        return ans;
    }
};