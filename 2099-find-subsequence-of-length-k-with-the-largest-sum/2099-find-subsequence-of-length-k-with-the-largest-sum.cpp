class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans=nums;
        sort(ans.begin(), ans.end(), greater<int>());
        map<int,int>mp;
        for(int i=0;i<k;i++)
        {
            mp[ans[i]]++;
        }
        
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end() and mp[nums[i]]>0)
            {
                result.push_back(nums[i]);
                mp[nums[i]]--;
            }
        }
        return result;
    }
};