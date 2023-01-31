class Solution {
public:
    int solve(int curidx, int previdx,  vector<pair<int,int>>&agescore, vector<vector<int>>&dp)
    {
        if(curidx>=agescore.size())
            return 0;
        if(dp[curidx][previdx+1]!=-1)
            return dp[curidx][previdx+1];
        
        int take=0;
        int nottake=0;
        if(previdx==-1 || agescore[curidx].second >= agescore[previdx].second)
        {
            take=agescore[curidx].second + solve(curidx+1,curidx,agescore,dp);
        }
        
        nottake=solve(curidx+1,previdx,agescore,dp);
        
        return dp[curidx][previdx+1]=max(take,nottake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pair<int,int>>agescore;
        
        for(int i=0;i<n;i++)
        {
            agescore.push_back({ages[i],scores[i]});
        }
        
        sort(agescore.begin(),agescore.end());
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return solve(0,-1,agescore,dp);
    }
};