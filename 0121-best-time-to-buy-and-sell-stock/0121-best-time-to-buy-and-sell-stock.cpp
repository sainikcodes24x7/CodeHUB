class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentbuy=INT_MAX;
        int profit=INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            currentbuy=min(currentbuy,prices[i]);
            profit=max(profit,prices[i]-currentbuy);
        }
        return profit;
    }
};