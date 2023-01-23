class Solution {
public:
    void helper(int idx, vector<vector<int>>&ans, vector<int>&dp, int target, int k,int n)
    {
        if(dp.size()==k)
        {
            if(target==0)
            {
                ans.emplace_back(dp);
                return ;
            }
            
        }
        
        for(int i=idx;i<=9;i++)
        {
            if(dp.size()>=k and target!=0)
            {
                break;
            }
            if(i>target)
                break;
            dp.emplace_back(i);
            helper(i+1,ans,dp,target-i,k,n);
            dp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>dp;
        if(k>n)
            return ans;
        helper(1,ans,dp,n,k,n);
        return ans;
    }
};