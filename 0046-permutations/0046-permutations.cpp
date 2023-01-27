class Solution {
public:
    vector<vector<int>>ans;
    void permute_help(vector<int>&nums, int start)
    {
        if(nums.size()==start)
            ans.push_back(nums);
        for(int i=start;i<nums.size();i++)
        {
            swap(nums[i],nums[start]);
            permute_help(nums,start+1);
            swap(nums[i],nums[start]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        permute_help(nums,0);
        return ans;
    }
};