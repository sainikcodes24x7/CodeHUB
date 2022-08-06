class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int prevnum=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            
            int currnum=nums[i];
            
            int noOftime=(currnum/prevnum);
            if(currnum%prevnum!=0)
            {
                //int noOftime=ceil(currnum/prevnum);
                noOftime++;
                prevnum=currnum/noOftime;
                
            }
            ans+=noOftime-1;
        }
        return ans;
    }
};