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
        for(int i=2;i<n;i++)
        {
            cost[i]=cost[i]+min(cost[i-2],cost[i-1]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};