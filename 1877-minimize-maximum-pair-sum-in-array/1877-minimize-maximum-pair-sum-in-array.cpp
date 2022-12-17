class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //int sum=0;
        int i=0,j=nums.size()-1;
        int n=nums.size();
        int sum=INT_MIN;
        while(i<j)
        {
            sum=max(sum,nums[i]+nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};