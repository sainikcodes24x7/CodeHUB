class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            totsum+=nums[i];
        }
        if(totsum%2==1)
            return false;
        else
        {
            int k=totsum/2;
            vector<vector<bool>>dp(n,vector<bool>(k+1,false));
            for(int i=0;i<n;i++)
            {
                dp[i][0]=true;
            }
            if(nums[0]<=k)
            {
                dp[0][nums[0]]=true;
            }
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<=k;j++)
                {
                    bool notaken=dp[i-1][j];
                    bool taken=false;
                    if(nums[i]<=j)
                        taken=dp[i-1][j-nums[i]];
                    
                    dp[i][j]=notaken||taken;
                }
            }
            return dp[n-1][k];
        }
    }
};