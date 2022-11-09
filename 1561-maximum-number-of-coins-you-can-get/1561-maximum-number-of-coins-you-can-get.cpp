class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // 1 2 2 4 7 8 
        // 2 7
        sort(piles.begin(),piles.end());
        int n=piles.size();
        
        int sum=0;
        for(int i=n/3;i<n;i+=2)
        {
            sum+=piles[i];
        }
        return sum;
    }
};