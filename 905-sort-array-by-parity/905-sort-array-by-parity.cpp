class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        for(auto i:nums)
        {
            if(i%2==0)
                ans.push_back(i);
        }
        for(auto i:nums)
        {
            if(i%2!=0)
                ans.push_back(i);
        }
        return ans;
    }
};