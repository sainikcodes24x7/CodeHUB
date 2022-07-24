class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
       set<pair<int,int>,greater<pair<int,int>>>p;
        
        vector<int>ans;
        for(auto it:mp)
        {
            p.insert({it.second,it.first});
        }
        
        for(auto it:p)
        {
            ans.push_back(it.second);
            k--;
           if(k==0)
                return ans;
        }
        return ans;
    }
};