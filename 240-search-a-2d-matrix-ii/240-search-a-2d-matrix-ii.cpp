class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=m-1,j=0;
        
        while(i>=0 and j<n){        
                if(target==matrix[i][j])
                    return true;
                else if(target<matrix[i][j])
                    i--;
                else
                    j++;
        }   
            
        
        return false;
    }
};