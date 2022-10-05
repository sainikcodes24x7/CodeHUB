class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited,int flag){
       if(visited[node] != -1) return ;
       visited[node] = flag ;
       for(auto i:adj[node]){
           dfs(i,adj,visited,flag) ;
       }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,-1) ;
        vector<vector<int>> adj(n) ;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]) ;
            adj[i[1]].push_back(i[0]) ;
        }
        int flag = 0 ;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(i,adj,visited,flag) ;
                flag++ ;
            }
        }
        unordered_map<int,int> mp ;
        for(auto i:visited){
            mp[i]++ ;
        }
        unsigned long long odd = 0 , even = 0 ;
        /*
         The actual calculation is to sum i.second*(n-i.second)/2 but 
         to avoid overflow odd and even are taken separately 
        */
        for(auto i:mp){
            if(i.second%2 == 0){
                even += i.second/2 * (n-i.second) ;
            }
            else if((n-i.second)%2 == 0){
                even += i.second * (n-i.second)/2 ;
            }
            else odd += i.second * (n-i.second) ;
        }
     return even + odd/2 ;
    }
};