class Solution {
public:
    void rotate(vector<vector<int>>& mat)
    {
        vector<vector<int>>arr=mat;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[j][n-i-1]=arr[i][j];
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)
            return true;
        for(int i=0;i<3;i++)
        {
            rotate(mat);
            if(mat==target)
                return true;
        }
        
        return false;
    }
};