class Solution {
public:
    bool isPossible(vector<string>temp, int row, int col, int n)
    {
        //vertically
        for(int i=row;i>=0;i--)
        {
            if(temp[i][col]=='Q')
                return false;
        }
        //diagonally top right
        for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++)
        {
           // for(int j=col+1;j<n;j++)
            //{
                if(temp[i][j]=='Q')
                    return false;
            //}
        }
        //diagonally top left
         for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--)
        {
            //for(int j=col-1;j>=0;j--)
            //{
                if(temp[i][j]=='Q')
                    return false;
            //}
        }
        return true;
    }
    void nqueen(vector<vector<string>>&ans, vector<string>temp, int row, int n)
    {
        if(row==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isPossible(temp,row,i,n))
            {
                temp[row][i]='Q';
                nqueen(ans,temp,row+1,n);
                temp[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        nqueen(ans,temp,0,n);
        return ans;
    }
};