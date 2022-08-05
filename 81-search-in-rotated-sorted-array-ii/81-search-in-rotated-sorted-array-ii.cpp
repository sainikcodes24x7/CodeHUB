class Solution {
public:
    bool binarysrch(int start, int end,vector<int>& nums, int target)
    {
        int mid;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(nums[mid]>target)
            {
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
                return true;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        //finding pivot
        int n=nums.size()-1;
        int pivot=nums.size()-1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                pivot=i;
                break;
            }
        }
        return (binarysrch(0,pivot-1,nums,target)||binarysrch(pivot,n,nums,target));
    }
};