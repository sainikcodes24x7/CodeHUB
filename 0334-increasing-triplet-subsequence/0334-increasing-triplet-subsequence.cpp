class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX;
        int second=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=first)
                first=nums[i]; // first greater ele
            else if(nums[i]<=second)
                second=nums[i];     // second greater ele
            else
                return true;
        }
        return false;
    }
};