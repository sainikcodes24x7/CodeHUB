class Solution {
public:
    /*
    int solvememo(vector<int>& nums, int n, int curr, int prev, vector<vector<int>>dp)
    {
        if(curr==n)
            return 0;
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        int take=0;
        
        // when she is taken
        if(prev==-1 || nums[curr]>nums[prev])
        {
            take=1+solvememo(nums,n,curr+1,curr,dp);
        }
        
        //when she is not taken
        int nottaken=0+solvememo(nums,n,curr+1,prev,dp);
        
        //that's what she said
        dp[curr][prev+1]=max(take,nottaken);
        return dp[curr][prev+1];
    }
    */
     int solvedp(vector<int>& nums, int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int take=0;
        
                // when she is taken
                    if(prev==-1 || nums[curr]>nums[prev])
        {
            take=1+dp[curr+1][curr+1];
        }
        
        //when she is not taken
        int nottaken=0+dp[curr+1][prev+1];
                dp[curr][prev+1]=max(take,nottaken);
            }
        }
        
        
        //that's what she said
        
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // for memorization
        /*
       vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solvememo(nums,n,0,-1,dp);
        */
        
        return solvedp(nums,n);
    }
};