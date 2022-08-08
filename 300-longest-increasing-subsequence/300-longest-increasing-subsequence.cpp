class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int maxlength=0;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    maxlength=max(maxlength,dp[j]);
            }
            dp[i]=maxlength+1;
        }
        int ans=INT_MIN;
        for(auto i:dp)
        {
            ans=max(ans,i);
        }
        return ans;
    }
};