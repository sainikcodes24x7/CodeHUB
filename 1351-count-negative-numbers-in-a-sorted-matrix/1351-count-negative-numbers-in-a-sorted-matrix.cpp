class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c=0;
        int i=0;
        int n=grid.size();
        int m=grid[0].size();
        int j=m-1;
        
        while((i<n and i>=0) and (j<m and j>=0))
        {
            if(grid[i][j]<0)
            {
                //c+=n-i;
                c++;
                if(j==0)
                {
                    i++;
                    j=m-1;
                }
                else
                j--;
            }
            else
            {
                i++;
                j=m-1;
            }
           
        }
        return c;
    }
};