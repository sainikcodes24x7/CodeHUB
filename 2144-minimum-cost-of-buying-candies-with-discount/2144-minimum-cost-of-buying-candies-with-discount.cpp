class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int i=n-1;
        int price=0;
        while(i>=0)
        {
            price+=cost[i];
            if(i-1>=0)
                price+=cost[i-1];
            i-=3;
        }
        return price;
    }
};