class Solution {
public:
    int maxProfit(vector<int>& prices) {
   
        int minbuyprice=INT_MAX;
        int maxprofit=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            minbuyprice=min(minbuyprice,prices[i]);
            maxprofit=max(maxprofit,prices[i]-minbuyprice);
        }
        return maxprofit;
    }
};