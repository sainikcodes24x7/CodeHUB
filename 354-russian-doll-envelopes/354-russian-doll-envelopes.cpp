class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int solveLIS(vector<int>&nums, int n)
    {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        sort(arr.begin(),arr.end(),cmp);
        vector<int>nums;
        //int k=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(arr[i][1]);
        }
        return solveLIS(nums,n);
    }
};