class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int crow=matrix.size()-1;
        int ccol=0;
        while(crow>=0 and ccol<matrix[0].size())
        {
            if(matrix[crow][ccol]<target)
                ccol++;
            else if(matrix[crow][ccol]>target)
                crow--;
            else
                return true;
        }
        return false;
    }
};