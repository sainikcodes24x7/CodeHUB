class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj[n];
        for(auto itr:prerequisites)
        {
            adj[itr[1]].push_back(itr[0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for (auto itr:adj[i])
            indegree[itr]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            ans.push_back(top);
            
            for(auto nbr:adj[top])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        if(ans.size()==n)
            return ans;
        return {};
    }
};