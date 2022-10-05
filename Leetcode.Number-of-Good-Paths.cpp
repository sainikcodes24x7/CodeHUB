class DSU{
    private:
    vector<int>par,size,rank;

   public:
    DSU(int n)
    {
        for(int i=0;i<=n;i++)
        {
            par.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    // by size+path 
    public:
    int findPar(int node)
    {
        if(par[node]==node)return node;  // i am groot
        return par[node]=findPar(par[node]);
    }

    public:
    void UnionSize(int u, int v)
    {
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu==pv)return;
        // size matters
        if(size[pu]>size[pv])
        {
            par[pv]=pu;
            size[pu]+=size[pv];
        }
        else 
        {
            par[pu]=pv;
            size[pv]+=size[pu];
        }

    }
    /*
     // by Rank 
    public:
    int findPar(int node)
    {
        if(par[node]==node)return node;  // i am groot
        return par[node]=findPar(par[node]);
    }

    public:
    void UnionRank(int u, int v)
    {
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu==pv)return;
        // Rank matters
        if(rank[pu]>rank[pv])
        {
            par[pv]=pu;
         //   size[pu]+=size[pv];
        }
        else if(rank[pv]>rank[pu])
        {
            par[pu]=pv;
        //    size[pv]+=size[pu];
        }
        else{
            par[pu]=pv;
            rank[pv]++;
        }

    }
    */

};



class Solution {
public:
    int numberOfGoodPaths(vector<int>& v, vector<vector<int>>& e) {
        int n=v.size();
        int paths=0;
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)mp[v[i]].push_back(i);
        vector<int> adj[n+1];
        for(auto &g : e)
        {
            int u=g[0],w=g[1];
            if(v[u]>=v[w])adj[u].push_back(w);
            if(v[w]>=v[u])adj[w].push_back(u);
        }
          DSU dsu(n);
        for(auto &i: mp)
        {
            for(auto &node: i.second)
            {
                for(auto &next : adj[node])
                {
                    dsu.UnionSize(node,next);
                }
            }
            unordered_map<int,int>grp;
            for(auto &node : i.second)
            {
                int par=dsu.findPar(node);
                grp[par]++;
            }
            paths+=i.second.size();
            for(auto &f : grp)
            {
                paths+=(f.second*(f.second-1)/2);
            }
        }
        return paths;
        
    }
};