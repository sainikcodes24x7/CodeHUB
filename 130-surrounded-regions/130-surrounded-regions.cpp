class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>>&ans)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || ans[i][j]==1 || board[i][j]=='X')
            return;
       ans[i][j]=1;
       for(int k=0;k<4;k++)
       {
           dfs(board,i+dx[k],j+dy[k],ans);
       }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && ans[i][0]!=1)
            {
                dfs(board,i,0,ans);
            }
            if(board[i][m-1]=='O' && ans[i][m-1]!=1)
            {
                dfs(board,i,m-1,ans);
            }
        }
          for(int i=0;i<m;i++)
        {   
            
            if(board[0][i]=='O' && ans[0][i]!=1)
            {
                dfs(board,0,i,ans);
            }
            if(board[n-1][i]=='O' && ans[n-1][i]!=1)
            {
                dfs(board,n-1,i,ans);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]!=1)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};