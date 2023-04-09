class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> dp(n, vector<int>(26));
        vector<int> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && dfs(i, adj, visited, dp, colors) == false) {
                return -1;
            }
            for (int j = 0; j < 26; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& visited, vector<vector<int>>& dp, string& colors) {
        visited[u] = 1;
        for (int v : adj[u]) {
            if (visited[v] == 1) {
                return false;
            }
            if (visited[v] == 0 && dfs(v, adj, visited, dp, colors) == false) {
                return false;
            }
            for (int j = 0; j < 26; j++) {
                dp[u][j] = max(dp[u][j], dp[v][j]);
            }
        }
        dp[u][colors[u] - 'a']++;
        visited[u] = 2;
        return true;
    }
};