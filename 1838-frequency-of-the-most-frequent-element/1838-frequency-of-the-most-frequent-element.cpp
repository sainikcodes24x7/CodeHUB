class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        long long j=0,excess=0,diff;
        long long ans=1;
        for(int i=1;i<n;i++)
        {
            diff=nums[i]-nums[i-1];
            excess=excess+(i-j)*diff;
            while(excess>k)
            {
                diff=nums[i]-nums[j];
                excess-=diff;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};