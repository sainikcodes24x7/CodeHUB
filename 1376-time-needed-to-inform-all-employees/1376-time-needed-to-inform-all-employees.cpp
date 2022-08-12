class Solution {
public:
    int dfs(vector<int>& manager,vector<int>& informTime,unordered_map<int,list<int>>&adj,int headID)
    {
        int count=0;
        for(auto itr:adj[headID])
        {
            count=max(count,dfs(manager,informTime,adj,itr));
        }
        return count+informTime[headID];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<n;i++)
        {
            if(i!=headID)
            {
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(manager,informTime,adj,headID);
    }
};