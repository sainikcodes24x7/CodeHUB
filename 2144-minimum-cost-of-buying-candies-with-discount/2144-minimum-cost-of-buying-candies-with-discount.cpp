class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int n=cost.size();
        if(n==1)
            return cost[0];
        if(n==2)
            return cost[0]+cost[1];
        int i=0;
        int price=0;
        
        while(i<n)
        {
            price+=cost[i];
            if(i+1<n)
                price+=cost[i+1];
            i+=3;
        }
        return price;
    }
};