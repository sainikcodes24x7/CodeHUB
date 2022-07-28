class Solution {
public:
    int dp2[2001][2001];
    int dp[2001];
    bool isPalin(string &s, int st, int e)
    {
        if(dp2[st][e]!=-1)
            return dp2[st][e];
        
        int i=st,j=e;
        
        if(st==e)
            return dp2[st][e]=1;
        else
        {
            while(i<j)
            {
                if(s[i]!=s[j])
                    return dp2[st][e]=0;
                i++;
                j--;
            }
        }
        return dp2[st][e]=1;
    }
    int mincuthelper(string &s, int i, int n)
    {
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        string temp="";
        
        for(int k=i;k<n;k++)
        {
            int total;
            temp+=s[k];
            
            if(isPalin(s,i,k))
            {
                total=1+mincuthelper(s,k+1,n);
                ans=min(ans,total);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        
        return mincuthelper(s,0,n)-1;
    }
};