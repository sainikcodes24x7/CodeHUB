class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x=1;
        for(auto i:nums)
        {
            if(i==x and i>0)
                x++;
        }
        return x;
    }
};