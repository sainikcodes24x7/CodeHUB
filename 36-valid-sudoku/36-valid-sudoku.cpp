class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false};
        bool col[9][9]={false};
        bool box[9][9]={false};
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int curr= board[i][j]-'0'-1;
                    int idx=i/3*3 +j/3;
                    if(row[i][curr] || col[j][curr] || box[idx][curr])
                        return false;
                    row[i][curr] = col[j][curr] = box[idx][curr]= true;
                }
            }
        }
        return true;
    }
};