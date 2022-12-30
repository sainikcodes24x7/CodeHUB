class Solution {
public:
    static vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.reserve(size(graph));
        path.push_back(0);
        dfs(graph, 0, path, ans);
        return ans;
    }
    
    static void dfs(const vector<vector<int>>& graph, int node, vector<int>& path,
	                vector<vector<int>>& ans) {
        const int dest = size(graph) - 1;
        if (node == dest) {
            ans.push_back(path);
            return;
        }
        
        for (int next : graph[node]) {
            path.push_back(next);
            dfs(graph, next, path, ans);
            path.pop_back();
        }
    }
};