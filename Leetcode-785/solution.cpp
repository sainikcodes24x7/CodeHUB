class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
       int n = adj.size() ;
        vector<int> color(n,-1);
        for(int i=1;i<n;++i)
            if(color[i]==-1){
                 queue<int> q;
        q.push(i);
        color[i] = 1;
        //Process current graph component using BFS
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int ele: adj[curr])
            {
                if(color[ele]==color[curr]) //Odd-cycle
                    return false;
                if(color[ele]==-1)  //Unvisited node
                {
                    color[ele] = 1-color[curr];
                    q.push(ele);
                }
            }
        }
            }
        return true;  
    }
};