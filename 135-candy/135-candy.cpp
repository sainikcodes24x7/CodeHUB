class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=0;
        int n=ratings.size();
        vector<int>dp(n+1);
        
        // initialize all elements as 1
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            if(ratings[i+1]>ratings[i])
                dp[i+1]=dp[i]+1;
        }
        for(int i=n-1;i>0;i--)
        {
            if(ratings[i-1]>ratings[i])
            {
                if(dp[i-1]<dp[i]+1)
                {
                    dp[i-1]=dp[i]+1;
                }
            }
                
        }
        for(int i=0;i<dp.size();i++)
        {
            sum+=dp[i];
        }
        return sum;
        
    }
};