class Solution {
public:
    unordered_set<int> st ;
    void dfs(vector<vector<int>>& isConnected , int src){
        st.insert(src) ;
        for(int i=0;i<isConnected[0].size();i++){
            if(isConnected[src][i]){
                if(src == i) isConnected[src][i] = 0 ;
                else{
                   isConnected[src][i] = 0 ;
                   isConnected[i][src] = 0 ;
                   dfs(isConnected,i) ;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0 ;
        for(int i=0;i<isConnected.size();i++)
        {
            if(st.count(i) == 0){
                ans++ ;
                dfs(isConnected,i) ;
            }
        }
     return ans ;
    }
};