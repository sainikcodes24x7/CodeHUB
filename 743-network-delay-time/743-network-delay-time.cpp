class Solution {
public:
  /*  void dfs(int k,vector<vector<pair<int,int>>>adj, int *dist)
    {
        for(auto nbr:adj[k])
        {
            if(dist[nbr.first]==INT_MAX)
            {
                dist[nbr.first]=dist[k]+nbr.second;
                dfs(nbr.first,adj,dist);
            }
            else if(dist[nbr.first]!=INT_MAX)
            {
                //dist[nbr.first]=max(dist[nbr.first],dist[k]+nbr.second);
                if(dist[nbr.first]>dist[k]+nbr.second)
                {
                    dist[nbr.first]=dist[k]+nbr.second;
                    dfs(nbr.first,adj,dist);
                }
                
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            /*int x=times[i][0];
            int y=times[i][1];
            int z=times[i][2];
            adj[x].push_back({y,z});
            */
/*            adj[times[i][0]].push_back( make_pair(times[i][1], times[i][2] ) );
        }
        int dist[n+1];
        for(int i=1;i<=n;i++)
        {
            dist[i]=INT_MAX;
        }
        
        dist[k]=0;
        dfs(k,adj,dist);
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
*/
  void dfs(int k , int *vis, vector<vector<pair<int,int>>> & adj )
    {
        for(auto it : adj[k])
        {
          
            if(vis[it.first]==INT_MAX)
            {
                vis[it.first] = vis[k] + it.second ;
                dfs(it.first, vis, adj);
            }
            else if(vis[it.first]!=INT_MAX)
            {
                if(vis[it.first] >  vis[k]+ it.second )
                {
                    vis[it.first]= vis[k]+ it.second;
                    dfs(it.first, vis, adj);
                }
            }
        }
      

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    { 
        vector<vector<pair<int , int >>> adj(n+1);
        for(int i =0;i<times.size();i++)
        adj[times[i][0]].push_back( make_pair(times[i][1], times[i][2] ) );
                                   
        int vis[n+1];
        for(int i =1;i<=n;i++)
        vis[i]=INT_MAX;
        vis[k]=0;
        dfs( k , vis, adj );
        int ans= INT_MIN;
        for(int i =1;i<=n;i++)
        {
            
            if(vis[i]==INT_MAX)
                return -1;
            ans = max(ans,vis[i]);
        }
        return ans;
    }
};   