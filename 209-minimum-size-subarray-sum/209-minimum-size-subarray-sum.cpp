class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        int start=0;
        int sum=0;
        for(int end=0;end<n;end++)
        {
            sum+=nums[end];
            while(sum>=target)
            {
                res=min(res,end-start+1);
                //start++;
                sum-=nums[start++];
            }
            
            
        }
        
        if(res==INT_MAX)
            return 0;
        return res;
    }
};