class Solution {
public:
    int numDistinct(string s, string t) {
        int m=t.length();
        int n=s.length();
        if(m>n)
        {
            return 0;
        }
        double dp[1001][1001];
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=0;
        }
         for(int j=0;j<=n;j++)
        {
            dp[0][j]=1;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(t[i-1]!=s[j-1])
                {
                    dp[i][j]=dp[i][j-1];
                   
                }
                else
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1]; 
                }
            }
        }
        return dp[m][n];
    }
};