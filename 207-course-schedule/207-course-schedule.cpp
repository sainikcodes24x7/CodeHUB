class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int>indegree(numCourses);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[temp].size();i++)
            {
               
                if(--indegree[adj[temp][i]]==0)
                    q.push(adj[temp][i]);
            }
        }
        if(count==numCourses)
            return true;
        return false;
    }
};