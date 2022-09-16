class Solution {
public:
    // declare a dp
    
    vector<vector<int>> dp;
    
    int helper(vector<int>& nums, int start, int end, int i, int m, vector<int>& multiplier)
    {
        // base case
        
        if(i == m)
            return 0;
        
        // if already calculated
        
        if(dp[i][start] != INT_MIN)
            return dp[i][start];
        
        // score after taking start element
        
        int from_front = nums[start] * multiplier[i] + helper(nums, start + 1, end, i + 1, m, multiplier);
        
        // score after taking end element
        
        int from_back = nums[end] * multiplier[i] + helper(nums, start, end - 1, i + 1, m, multiplier);
        
        // take the maximum of both and store in dp
        
        return dp[i][start] = max(from_front, from_back);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multiplier) {
        
        int n = nums.size();
        
        int m = multiplier.size();
        
        // resize dp
        
        dp.resize(m + 1);
        
        // initialize dp with INT_MIN
        
        dp.assign(m + 1, vector<int> (m + 1, INT_MIN));
        
        // call helper function
        
        return helper(nums, 0, n - 1, 0, m, multiplier);
    }
        
    
};