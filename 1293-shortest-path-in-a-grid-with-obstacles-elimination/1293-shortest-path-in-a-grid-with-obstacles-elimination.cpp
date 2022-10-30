class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,-1));
        
        queue<vector<int>> qu;
        qu.push({0, 0, 0, k});
        while(!qu.empty()){
            
            auto t = qu.front();
            qu.pop();
            int x = t[0], y = t[1];
            if(x<0 || y<0 || x>=m || y>=n) continue;
            if(x==m-1 && y==n-1) return t[2];
            // obstacle
            if(grid[x][y] == 1){
                if(t[3] >0) t[3]--; // If we have k remainaning
                else continue;      // Else stop this way
            }
            
            if(visited[x][y]!=-1 && visited[x][y] >= t[3]) continue; // Check if we have less k for this path, pass if yes
            
            visited[x][y] = t[3];
            qu.push({x+1,y,t[2]+1, t[3]});
            qu.push({x-1,y,t[2]+1, t[3]});
            qu.push({x,y+1,t[2]+1, t[3]});
            qu.push({x,y-1,t[2]+1, t[3]});
        }
        return -1;
    }
};