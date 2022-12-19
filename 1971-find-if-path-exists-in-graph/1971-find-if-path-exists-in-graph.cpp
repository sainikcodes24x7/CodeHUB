class Solution {
public: 
    void fillNeighbours(vector<vector<int>> &edges,vector<int>nbr[])
    {
        for(int i=0;i<edges.size();i++){
        nbr[edges[i][0]].push_back(edges[i][1]);
        nbr[edges[i][1]].push_back(edges[i][0]);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>nbr[n];
        fillNeighbours(edges,nbr);
        if(source==destination)
        {
            return true;
        }
        queue<int>q;
        q.push(source);
       map<int,bool>visited;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            visited[top]=1;
            
            for(auto i:nbr[top])
            {
                if(i==destination)
                {
                    return true;
                }
                else if(!visited[i])
                {
                    q.push(i);
                }
                    
            }
        }
        return false;
        
    }
};