class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxval=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(maxval==nums[i])
                count++;
            else
            {
                ans=max(ans,count);
                count=0;
            }
        }
        return max(ans,count);
    }
};