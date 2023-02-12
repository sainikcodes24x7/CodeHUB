class Solution {
public:
    long long ans=0;
    long long dfs(int node, int seats, vector<int>adj[], vector<int>&vis)
    {
        vis[node]=1;
        long long count=1;
        for(auto nbr:adj[node])
        {
            if(!vis[nbr])
                count+=dfs(nbr,seats,adj,vis);
        }
        
        int x=count/seats;
        if(count%seats)
            x++;
        if(node!=0)
            ans+=x;
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int>adj[n+1];
        vector<int>vis(n+1,0);
        
        for(auto itr:roads)
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        dfs(0,seats,adj,vis);
        return ans;
    }
};