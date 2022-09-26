class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        int k=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                k=nums[i];
            }
            else
            {
                s.insert(nums[i]);
            }
        }
        return k;
    }
};