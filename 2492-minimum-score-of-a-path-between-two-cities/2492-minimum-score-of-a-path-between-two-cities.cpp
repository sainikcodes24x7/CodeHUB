class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(auto road:roads)
        {
            int u=road[0];
            int v=road[1];
            int w=road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int res=INT_MAX;
        queue<int>q;
        q.push(1);
        unordered_set<int>vis;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto &[nbr,score]:adj[node])
            {
                if(!vis.count(nbr))
                {
                    vis.insert(nbr);
                    q.push(nbr);
                }
                res=min(res,score);
            }
        }
        return res;
    }
};