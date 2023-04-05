#include<algorithm>
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
         long long int maxvalue = 0;
        long long int suntillnow = 0;
        int n=nums.size();
        for (int i = 1; i <= n; i++ )
           
        {
            suntillnow += nums[i-1];
             maxvalue = max(maxvalue, (suntillnow+i-1)/i);
        }
        return maxvalue;
        
    }
    
};