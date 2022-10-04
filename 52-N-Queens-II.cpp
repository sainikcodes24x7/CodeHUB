class Solution
{
public:
    bool issafe(vector<vector<int>> &board, int row, int col, int n)
    {
        int x = row;
        int y = col;
        while (y >= 0)
        {
            if (board[x][y] == 1)
                return false;
            y--;
        }
        x = row;
        y = col;
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 1)
                return false;
            x--;
            y--;
        }
        x = row;
        y = col;
        while (x < n && y >= 0)
        {
            if (board[x][y] == 1)
                return false;
            x++;
            y--;
        }
        return true;
    }
    void solve(vector<vector<int>> &board, int &count, int col, int n)
    {
        if (col == n)
        {
            count++;
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (issafe(board, row, col, n))
            {
                board[row][col] = 1;
                solve(board, count, col + 1, n);
                board[row][col] = 0;
            }
        }
    }
    int totalNQueens(int n)
    {
        if (n == 1)
            return 1;
        vector<vector<int>> board(n, vector<int>(n, 0));
        int col = 0;
        int count = 0;
        solve(board, count, col, n);
        return count;
    }
};