class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==1 and mp[nums[i]-1]==0 and mp[nums[i]+1]==0)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};