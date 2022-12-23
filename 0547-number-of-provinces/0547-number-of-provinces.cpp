class Solution {
public:
    int ans,c=0,n;
    int vis[201]={0};
    void dfs(int start, vector<vector<int>>& isConnected)
    {
        vis[start]=true;
        c++;
        for(int connection=0;connection<n;connection++)
        {
            if(!vis[connection] and isConnected[start][connection])
                dfs(connection,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
       // for(int i=0;i<n;i++)    
        for(int i = 0;i<n;i++) if(!vis[i]) c=0,dfs(i,isConnected),ans++;;
        return ans; 
              
                
        
       // return ans;
    }
};