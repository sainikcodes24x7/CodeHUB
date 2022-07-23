class Solution {
public:
    bool isvalid(int row, int col,vector<vector<char>>& board,int val )
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]-'0'==val)
                return false;
        }
        for(int i=0;i<9;i++)
        {
            if(board[i][col]-'0'==val)
                return false;
        }
        for(int i=0;i<9;i++)
        {
            if(board[3*(row/3) +(i/3)][3*(col/3) +(i%3)]-'0'==val)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int x=board[i][j]-'0';
                    board[i][j]='.';
                    if(isvalid(i,j,board,x))
                    {
                        board[i][j]=x;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};