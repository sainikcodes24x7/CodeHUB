class Solution {
    int res,c = 0,n,vis[201]={0};
    void dfs(vector<vector<int>>& isConnected,int start){
        vis[start] = true;c++;
        for(int connection = 0;connection<n;connection++){
            if(!vis[connection] and isConnected[start][connection]) dfs(isConnected,connection);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        for(int i = 0;i<n;i++) if(!vis[i]) c=0,dfs(isConnected,i),res++;;
        return res;   
    }
};