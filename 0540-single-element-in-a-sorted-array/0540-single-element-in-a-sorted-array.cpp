class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto itr:mp)
        {
            if(itr.second==1)
                return itr.first;
        }
        return -1;
    }
};