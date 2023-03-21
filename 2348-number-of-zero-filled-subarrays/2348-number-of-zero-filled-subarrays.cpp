class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long totalcount=0;
        long long currcount=0;
        for(auto i:nums)
        {
            // whenever we are getting 0, we are increasing count
            if(i==0)
                currcount++;
            else
            {
                // here we are calculating no of pairs of subarrays
                totalcount=totalcount+(currcount*(currcount+1))/2;
                currcount=0;
            }
            
        }
        totalcount=totalcount+(currcount*(currcount+1))/2;
        return totalcount;
    }
};