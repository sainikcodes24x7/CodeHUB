class Solution {
public:
    int solve(string &s, int curr, int prev, int &k, vector<vector<int>>&dp)
    {
        if(curr>=s.length())
            return 0;
        if(dp[curr][prev]!=-1)
            return dp[curr][prev];
        int inc=0,notinc=0;
        if(prev==0 || abs(s[curr]-prev)<=k)
            inc=1+solve(s,curr+1,s[curr],k,dp);
        notinc=solve(s,curr+1,prev,k,dp);
        dp[curr][prev]=max(inc,notinc);
        return dp[curr][prev];
    }
    int longestIdealString(string s, int k) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(150,-1));
        return solve(s,0,0,k,dp);
    }
};