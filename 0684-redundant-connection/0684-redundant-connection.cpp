class Solution {
public:
     vector<int>parents;
        int findset(int a)
        {
            if(a==parents[a])
                return a;
            return a=findset(parents[a]);
        }
        int unionfind(int a, int b)
        {
            a=findset(a);
            b=findset(b);
            if(a==b)
                return true;
            parents[b]=a;
            return false;
        }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n=edges.size();
        for(int i=0;i<=n;i++)
        {
            parents.push_back(i);
        }
        for(auto itr:edges)
        {
            if(unionfind(itr[0],itr[1]))
                return {itr[0],itr[1]};
        }
        return {-1,-1};
      }
};