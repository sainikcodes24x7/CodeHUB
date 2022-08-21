class Solution {
public:
    int dx[8]={-2,2,-1,1,2,-2,-1,1};
    int dy[8]={1,1,2,-2,-1,-1,-2,2};
    double knightProbability(int n, int k, int row, int column) {
        if(k==0)
            return 1.0;
        vector<vector<double>>v1(n+1,vector<double>(n,0.0));
        v1[row][column]=1.0;
        while(k--){
            vector<vector<double>>v2(n+1,vector<double>(n,0.0));
            
            for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                double prob=v1[i][j]/8.0;
                for(int z=0;z<8;z++)
                {
                    int x=i+dx[z];
                    int y=j+dy[z];
                    
                    if(x>=0 and x<n and y>=0 and y<n)
                    {
                        v2[x][y]+=prob;
                    }
                }
            }
        }
            v1=v2;
        }
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=v1[i][j];
            }
        }
        return ans;
    }
};