class Solution {
    void dfs(int i, int j, vector<vector<int>> &g){
        // out of bound OR visited
        if(i<0 or j<0 or i==g.size() or j==g[i].size() or g[i][j]==1)return;
        
        g[i][j]=1; // mark visited
        // down
        dfs(i+1, j, g);
        // up
        dfs(i-1, j, g);
        // right
        dfs(i, j+1, g);
        // left
        dfs(i, j-1, g);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        // creatr 3n * 3n grid
        vector<vector<int>> graph(3*n, vector<int>(3*n, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/') // mimic forward slash: mark (3i,3j+2), (3i+1,3j+1), (3i+2,3j) as visited 
                    graph[3*i][3*j + 2] = graph[3*i + 1][3*j + 1] = graph[3*i + 2][3*j] = 1;
                else if(grid[i][j]=='\\') // mimic backward slash: mark (3i,3j), (3i+1,3j+1), (3i+2,3j+2) as visited 
                    graph[3*i][3*j] = graph[3*i + 1][3*j + 1] = graph[3*i + 2][3*j + 2] = 1;
            }
        }
        int res = 0;
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                // if cell isn't visited
                if(graph[i][j]==0){
                    res++; // increase counter
                    dfs(i,j,graph); // visit all neighbors
                }
            }
        }
        return res;
    }
};
