class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        //if(n==0)
        //    return -1;
        int maxsofar=nums[0];
        int maxsumend=nums[0];
        for(int i=1;i<n;i++)
        {
            maxsofar=max(maxsofar+nums[i],nums[i]);
            //if(maxsofar<0)
            //    maxsofar=0;
            maxsumend=max(maxsumend,maxsofar);
        }
        return maxsumend;
       
       
    }
};