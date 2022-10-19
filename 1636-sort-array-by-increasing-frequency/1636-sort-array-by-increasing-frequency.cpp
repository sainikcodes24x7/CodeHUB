class Solution {
public:
    static bool comp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
            return p1.first>p2.first;
        return p1.second<p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(auto itr:nums)
        {
            mp[itr]++;
        }
        vector<pair<int,int>>ans;
        for(auto itr:mp)
        {
            ans.push_back({itr.first,itr.second});
        }
        sort(ans.begin(),ans.end(),comp);
        
        for(auto i:ans)
        {
            cout<<i.first<<" ";
        }
        
        vector<int>res;
        for(auto i:ans)
        {
            while(i.second--)
            res.push_back(i.first);
        }
        return res;
    }
};