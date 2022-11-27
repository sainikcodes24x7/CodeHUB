class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        // declare a dp array of unordered_map
        
        vector<unordered_map<long, long>> dp(n + 1);
        
        // dp[i][diff] will store the no. of subsequence with common difference of diff, till ith index
        
        long ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                long diff = (long) nums[i] - long(nums[j]);
                
                // update ans
                
                ans += dp[j][diff];
                
                // update dp[i][diff]
                
                dp[i][diff] += dp[j][diff];
                
                dp[i][diff]++;
            }
        }
        
        return ans;
    }
};