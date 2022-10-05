class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int s=0;
    
        for(int i=0;i<nums.size();i++)
        {
            
                s=s+nums[i];
                   nums[i]=s;            
        }
        return nums;
        
    }
};