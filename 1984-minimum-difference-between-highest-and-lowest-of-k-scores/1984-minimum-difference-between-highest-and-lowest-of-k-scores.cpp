class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=INT_MAX;
        int j=k-1;
        int i=0;
        while(j<n)
        {
            res=min(res,nums[j]-nums[i]);
            i++;
            j++;
        }
        return res;
    }
};