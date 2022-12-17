class Solution {
public:
    int first_pos(int start, int end, vector<int>& nums, int target)
    {
        int result=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                result=mid;
                end=mid-1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return result;
    }
    int last_pos(int start, int end, vector<int>& nums, int target)
    {
        int result=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                result=mid;
                start=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0, end=nums.size()-1;
        vector<int>ans(2);
        ans[0]=first_pos(start,end,nums,target);
        ans[1]=last_pos(start,end,nums,target);
        return ans;
    }
};