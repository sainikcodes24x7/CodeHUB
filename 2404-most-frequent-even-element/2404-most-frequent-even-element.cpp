class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                mp[nums[i]]++;
            }
        }
         for(auto i:mp)
        {
           cout<<i.first<<" "<<i.second<<endl;
        }
        int maxcount=0;
        int ans=-1;
        for(auto i:mp)
        {
            if(i.second>maxcount)
            {
                maxcount=i.second;
                ans=i.first;
            }
            else if(i.second==maxcount)
                ans=min(ans,i.first);
        }
        return ans;
    }
};