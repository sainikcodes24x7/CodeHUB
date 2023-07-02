//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int idx,vector<vector<int>> &adj, vector<int>&vis, int V){
        vis[idx]=1;
        
        for(int i=0;i<V;i++){
            if(vis[i]==0 and adj[idx][i]==1)
            dfs(i,adj,vis,V);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>vis(V+1,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis,V);
            }
            
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends