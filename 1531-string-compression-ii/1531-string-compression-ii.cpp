class Solution {
public:
    int getlength(int count)
    {
        if(count==1)
            return 1;
        if(count<10)
            return 2;
        if(count<100)
            return 3;
        else
            return 4;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n=s.size();
        int dp[n+1][k+1];
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<=k;j++)
            {
                if(i==n)
                {
                    dp[n][j]=0;
                    continue;
                }
                if(j>0)
                {
                    dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=INT_MAX;
                }
                
                int posdel=j;
                int count=0;
                for(int end=i;end<n and posdel>=0;end++)
                {
                    if(s[end]==s[i])
                    {
                        count++;
                        dp[i][j]=min(dp[i][j],getlength(count)+dp[end+1][posdel]);
                    }
                    else
                    {
                        posdel--;
                    }
                }
                
                
                
            }
        }
        return dp[0][k];
    }
    
};