class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
            
        }
        for(auto i:mp)
        {
            if(i.second>ceil(n/3))
                ans.push_back(i.first);
        }
        return ans;
    }
};