class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num=1;
        int n=nums.size();
        vector<int>ans(n);
        
        // fill the array with product of left elements before the index
        for(int i=0;i<n;i++)
        {
            ans[i]=num;  //1 1 2 6
            num*=nums[i]; //1 2 6 24
        }
        num=1;
        
        // fill the array with product of right elements after the index
         for(int i=n-1;i>=0;i--)
        {
            ans[i]*=num;    // 24 12  8  6
            num*=nums[i]; //   24 12 4
        }
        return ans;
    }
};