class Solution {
public:
    int arrangeCoins(int n) {
        int sum=n;
        if(n==1)
            return 1;
        if(n==0)
            return 1;
        int i=1;
        
        while(sum>0)
        {
            i++;
            sum-=i;
        }
         return i-1;
    }
};