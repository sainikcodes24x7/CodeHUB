class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxcnt=1;
        int cnt=1;
        if(n==1 and nums[0]==1)
            return 1;
        if(n==1 and nums[0]==0)
            return 0;
        if(n==2 and nums[0]==0 and nums[1]==0)
            return 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==1 and nums[i-1]==1)
            {
                cnt++;
                maxcnt=max(cnt,maxcnt);
            }
            else
                cnt=1;
        }
        return maxcnt;
        
    }
};