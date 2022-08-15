class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxtillnow=0;
        if(nums[0]==0 and nums.size()==1)
            return true;
        for(int i=0;i<nums.size();i++)
        {
            if(maxtillnow<i)
            {
                return false;
                
            }
            maxtillnow=max(maxtillnow,i+nums[i]);
                
        }
        return maxtillnow;
    }
};