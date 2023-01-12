class Solution {
public:
    vector<int>helper(vector<vector<int>>&adj, string &labels, int cur, vector<int>&res)
    {
        vector<int>ans(26,0);
        res[cur]=1;
        ans[labels[cur]-'a']=1;
        
        for(int j=0;j!=adj[cur].size();j++)
        {
            if(!res[adj[cur][j]])
            {
                vector<int>tmp=helper(adj,labels,adj[cur][j],res);
                for(int k = 0; k != 26; k++) 
                    ans[k] += tmp[k];
            }
                
        }
        res[cur]=ans[labels[cur]-'a'];
        return ans;
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        vector<int>result(n,0);
        for(int i=0;i!=edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        helper(adj,labels,0,result);
        return result;
    }
};