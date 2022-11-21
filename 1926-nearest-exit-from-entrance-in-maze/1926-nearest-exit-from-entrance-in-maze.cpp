class Solution {
public:
    vector<int>rowmat={-1,0,1,0};
    vector<int>colmat={0,1,0,-1};
    bool isatborder(vector<vector<char>>& maze, int row, int col)
    {
        if(row==0 || row==maze.size()-1)
            return true;
        if(col==0 || col==maze[0].size()-1)
            return true;
        return false;
    }
    bool isvalid(vector<vector<char>>& maze, int &row, int &col)
    {
        int n=maze.size();
        int m=maze[0].size();
        if(row<0 || row==n || col<0 || col==m || maze[row][col]=='+' )
            return false;
        else
            return true;
        
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        int path=0;
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int currow=q.front().first;
                int curcol=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int newrow=currow+ rowmat[i];
                    int newcol=curcol+ colmat[i];
                    if(isvalid(maze,newrow,newcol))
                    {
                        maze[newrow][newcol]='+';
                        if(isatborder(maze,newrow,newcol))
                            return path+1;
                        else
                            q.push({newrow,newcol});
                    }
                }
                    
            }
            path++;
        }
            return -1;
            
    }
};