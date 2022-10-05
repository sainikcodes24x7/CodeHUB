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
    private:
    bool isMatching(string& s1, string& s2)
    {
        int unmatched=0;
        for(int i=0;i<s1.size();i++)
            unmatched+=(s1[i]!=s2[i]);
          return (unmatched==2 or unmatched==0);
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        if(strs[0].size()<=2)return 1;
        int n=strs.size();
        DSU dsu(n);
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string s1=strs[i];
                string s2=strs[j];
                
                if(isMatching(s1,s2))
                {
                    dsu.UnionSize(i,j);
                }
            }
        }
        
        unordered_set<int>cc;
        for(int i=0;i<n;i++)cc.insert(dsu.findPar(i));
        return cc.size();
    }
};