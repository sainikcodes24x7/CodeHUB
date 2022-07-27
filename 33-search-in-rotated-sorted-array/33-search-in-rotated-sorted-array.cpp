class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid;
        while(s<=e)
        {
            mid=(s+e)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>=nums[s])
            {
                if(target>=nums[s] and target<=nums[mid])
                    e=mid-1;
                else
                    s=mid+1;
            }
            else
            {
                if(target<=nums[e] and target>=nums[mid])
                    s=mid+1;
                else
                    e=mid-1;
            }
        }
        return -1;
    }
};