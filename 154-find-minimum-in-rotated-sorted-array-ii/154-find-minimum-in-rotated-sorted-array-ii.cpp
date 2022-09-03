class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int m=(s+e)/2;
        while(s<e)
        {
            if(nums[m]>nums[e])
                s=m+1;
            else if(nums[m]<nums[e])
                e=m;
            else
                e--;
            m=(s+e)/2;
        }
        return nums[s];
    }
};