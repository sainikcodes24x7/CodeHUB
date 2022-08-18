class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       /* cost.push_back(0);
        for(int i=cost.size()-3;i>-1;i--)
        {
            cost[i]=min((cost[i]+cost[i+1]),(cost[i]+cost[i+2]));
        }
        return min(cost[0],cost[1]);
        */
        
        int n=cost.size();
        vector<int>dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
        
    }
};