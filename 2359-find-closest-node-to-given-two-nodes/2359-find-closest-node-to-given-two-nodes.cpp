class Solution {
public:
    void dfs(int node,vector<int>&dist, vector<int>&edges,vector<bool>&visited, int distance)
    {
        if(node!=-1 and !visited[node])
        {
            visited[node]=1;
            dist[node]=distance;
            dfs(edges[node],dist,edges,visited,distance+1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        vector<bool>visited(n,0);
        
        int ans=INT_MAX;
        int index=-1;
        dfs(node1,dist1,edges,visited,0);
        visited.assign(n,0);
        dfs(node2,dist2,edges,visited,0);
        
        for(int i=0;i<n;i++)
        {
            if(max(dist1[i],dist2[i])<ans)
            {
                ans=max(dist1[i],dist2[i]);
                index=i;
            }
        }
        return index;
    }
};