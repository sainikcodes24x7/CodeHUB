class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int i;
        for(i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
                break;
        }
        if(i==n)
            return nums[0];
        else
        return min(nums[0],nums[i]);
    }
};