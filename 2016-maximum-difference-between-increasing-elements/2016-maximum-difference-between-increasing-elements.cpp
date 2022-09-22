class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdiff=INT_MIN;
        int minstart=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            minstart=min(minstart,nums[i]);
            maxdiff=max(maxdiff,nums[i]-minstart);
            cout<<maxdiff<<" ";
        }
        if(maxdiff>0)
        return maxdiff;
        return -1;
    }
};