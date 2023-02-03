class Solution {
public:
    int jump(vector<int>& nums) {
        int maxsum=0,cursum=0,c=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            cursum=max(cursum,i+nums[i]);
        
        if(i==maxsum)
        {
            c++;
            maxsum=cursum;
            
        }
    }
        return c;
    }
};