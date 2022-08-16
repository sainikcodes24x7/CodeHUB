class Solution {
public:
    int edgeScore(vector<int>& edges) {
        //unordered_map<long long int,list<int>>adj(edges.size());
        vector<long long int>adj[edges.size()];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i]].push_back(i);
        }
        long long int maxsum=0,minval=0;
        
        for(int i=0;i<edges.size();i++)
        {
            long long int sum=0;
            for(int j=0;j<adj[i].size();j++)
            {
                sum+=adj[i][j];
            }    
                if(sum>maxsum)
                {
                    maxsum=sum;
                    minval=i;
                }
            
        }
        return minval;
    }
};