class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto itr:nums)
        {
            sum+=itr;
        }
        if(sum%2!=0)
            return false;
        
        vector<bool>dp(sum/2+1,false);
        dp[0]=true;
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            for(int j=min(s,sum/2);j>=nums[i];j--)
            {
                if(dp[j-nums[i]])
                    dp[j]=true;
            }
        }
        return dp[sum/2];
    }
};