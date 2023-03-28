class Solution {
public:
    vector<int>dp;
    int helper(vector<int>& days, vector<int>& costs, int start)
    {
        int n=days.size();
        if(start>=n)
        {
            return 0;
        }
        if(dp[start])
            return dp[start];
        
        int oneday=costs[0]+helper(days,costs,start+1);
        
        int i;
        //int weekly;
        for(i=start;i<n and days[i]<days[start]+7;i++);
        
            int weekly=costs[1]+helper(days,costs,i);
        
        
        //int monthly;
        for(i=start;i<n and days[i]<days[start]+30;i++);
        
            int monthly=costs[2]+helper(days,costs,i);
        
        
        return dp[start]=min(oneday,min(monthly,weekly));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(367);
        return helper(days,costs,0);
    }
};