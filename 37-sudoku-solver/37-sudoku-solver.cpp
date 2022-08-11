class Solution {
public:
    bool isValid(int i,int j,int n, int m, char num,vector<vector<char>>& board)
    {
        for(int k=0;k<n;k++)
        {
            if(board[k][j]==num)
                return false;
            if(board[i][k]==num)
                return false;
        }
        int col=(j/3)*3;
        int row=(i/3)*3;
        for(int a=row;a<row+3;a++)
        {
            for(int b=col;b<col+3;b++)
            {
                if(board[a][b]==num)
                    return false;
            }
        }
        return true;
    }
    bool solvesudoku(vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char no='1';no<='9';no++)
                    {
                        if(isValid(i,j,n,m,no,board))
                        {
                            board[i][j]=no;
                            if(solvesudoku(board))
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
         solvesudoku(board);
            }
};