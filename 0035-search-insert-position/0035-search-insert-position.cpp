class Solution {
public:
    //int binarysearch(vector<int>& nums, int target)
        
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int mid=(i+j)/2;
        while(i<=j)
        {
             mid=(i+j)/2;
            if(target>nums[mid])
            {
                i=mid+1;
            }
            else if(target<nums[mid])
            {
                j=mid-1;
            }
            else
            {
                return mid;
            }
        }
        return i;
    }
};