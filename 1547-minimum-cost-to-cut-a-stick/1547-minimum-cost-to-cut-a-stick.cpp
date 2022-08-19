class Solution {
public:
    int tabulation(int n, int m, vector<int>&cuts)
    {
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>=1;i--)
        {
            for(int j=1;j<=m;j++)
            {
                if(i<=j)
                {
                    int ans=INT_MAX;
                    for(int k=i;k<=j;k++)
                    {
                        ans=min(ans,dp[i][k-1]+dp[k+1][j]+cuts[j+1]-cuts[i-1]);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[1][m];
    }
    int minCost(int n, vector<int>& cuts) {
        // we first insert 0 and n
        int m=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        sort(cuts.begin(),cuts.end());
        
        return tabulation(n,m,cuts);
    }
};