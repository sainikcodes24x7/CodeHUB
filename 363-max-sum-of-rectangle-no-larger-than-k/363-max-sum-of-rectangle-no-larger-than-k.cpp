class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
         int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> ver(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            ver[0][i]=matrix[0][i];
            for(int j=1;j<m;j++) ver[j][i]=1LL*(ver[j-1][i]+matrix[j][i]);
        }
        int res=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int i1=i;i1<m;i1++){
                    int curr=0;
                    for(int j1=j;j1<n;j1++){
                        curr=curr+ver[i1][j1]-((!i)?0:ver[i-1][j1]);
                        if(curr<=k) res=max(res,curr);
                    }
                }
            }
        }
        return res;
    }
};