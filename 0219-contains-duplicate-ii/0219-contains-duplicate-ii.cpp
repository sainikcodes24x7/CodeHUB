class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>s;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=i;
            else if(i-mp[nums[i]]<=k)
            {
                return true;
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return false;
    }
};