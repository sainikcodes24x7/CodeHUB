class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int>mp;
        for(auto itr:nums)
        {
            mp[itr]++;
        }
        int mingle=0;
        int single=0;
        for(auto itr:mp)
        {
            if(itr.second%2==0)
            {
                mingle+=(itr.second)/2;
                
            }
            else
            {
                 mingle+=(itr.second)/2;
                 single++;
            }
        }
        return {mingle,single};
    }
};