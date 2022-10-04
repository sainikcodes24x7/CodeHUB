class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int res=INT_MAX;
        int sum=0;
        while(j<n)
        {
            res=min(nums[i],nums[j]);
            sum+=res;
            
            i+=2;
            j+=2;
        }
        return sum;
    }
};