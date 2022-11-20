class Solution {
public:
    int atmostk(vector<int>&nums, int n, int k)
    {
        int left=0;
        int right=0;
        int count=0;
        
        unordered_map<int,int>mp;
        while(right<n)
        {
            if(mp.find(nums[right])==mp.end())
                mp[nums[right]]=1;
            else
                mp[nums[right]]++;
        
        while(mp.size()>k)
        {
            mp[nums[left]]--;
            if(mp[nums[left]]==0)
                mp.erase(nums[left]);
            left++;
        }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return atmostk(nums,n,k)- atmostk(nums,n,k-1);
    }
};