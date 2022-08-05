class Solution {
public:
    vector<int> dp;
   Solution() {
        dp.resize(1001);
        fill(dp.begin(), dp.end(), -1);
    }
    int helper(vector<int>& nums, int target, int cursum)
    {
        if(cursum>target)
            return 0;
        if(cursum==target)
            return 1;
        if(dp[cursum]!=-1)
            return dp[cursum];
        int ways=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cursum+nums[i]<=target)
            {
                ways+=helper(nums,target,cursum+nums[i]);
            }
        }
        dp[cursum]=ways;
        return dp[cursum];
    }
    int combinationSum4(vector<int>& nums, int target) {
        //vector<int>dp(10001,-1);
        //dp.resize(1001);
        //fill(dp.begin(), dp.end(), -1);
        //memset(dp,-1,sizeof(dp));
        int currentsum=0;
        return helper(nums,target,currentsum);
    }
};