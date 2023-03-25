class Solution {
public:
    
   void dfs(vector<int> adj[], int node , vector<int>&vis, int &c){
        c++;
        vis[node] =1;
        for(auto a : adj[node]){
            if(!vis[a]){
                dfs(adj,a,vis,c);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& ed) {
        vector<int> adj[n];
        for(auto a : ed){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> vis(n,0);
        long long ans=0;
        long long su=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis,c);
                ans += su*c;
                su +=c;
                c=0;
            }
        }
        return ans;
    }
};