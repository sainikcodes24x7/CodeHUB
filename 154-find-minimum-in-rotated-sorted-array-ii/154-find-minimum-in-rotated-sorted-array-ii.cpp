class Solution {
public:
    int findMin(vector<int>& nums) {
        int minele=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            minele=min(minele,nums[i]);
        }
        return minele;
    }
};