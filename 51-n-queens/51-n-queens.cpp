class Solution {
public:
    bool issafe(int col, int row, vector<string>temp, int n )
    {
        for(int i=0;i<=row;i++)
        {
            if(temp[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--)
        {
            if(temp[i][j]=='Q')
                return false;
        }
        for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++)
        {
            if(temp[i][j]=='Q')
                return false;
        }
        return true;
    }
    void nqueens(vector<vector<string>>&ans,vector<string>temp,int r, int n )
    {
        if(r==n)
            ans.push_back(temp);
        for(int i=0;i<n;i++)
        {
            if(issafe(i,r,temp,n))
            {
                temp[r][i]='Q';
                nqueens(ans,temp,r+1,n);
                temp[r][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        nqueens(ans,temp,0,n);
        return ans;
    }
};