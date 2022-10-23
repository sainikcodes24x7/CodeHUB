class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto itr:nums)
        {
            mp[itr]++;
        }
        int twice,absent;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>1)
            {
                twice=nums[i];
                break;
            }
                
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(mp[i]==0)
            {
                absent=i;
                break;
            }
        }
        return {twice,absent};
    }
};