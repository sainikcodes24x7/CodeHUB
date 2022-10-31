class Solution {
public:
  /*  bool checkdiag(int r, int c, vector<vector<int>>& matrix, int n, int m)
    {
        int temp=matrix[r][c];
        while(r<n and c<m)
        {
            if(matrix[r][c]!=temp)
                return false;
            r++;
            c++;
        }
        return true;
    }
    */
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
       // int i=0,j=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i>0 and j>0 and matrix[i][j]!=matrix[i-1][j-1])
                    return false;
            }
           
        }
        return true;
    }
};