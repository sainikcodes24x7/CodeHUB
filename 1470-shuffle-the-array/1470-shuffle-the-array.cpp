class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j=n;
        int m=nums.size();
        int i=0,k=0;
        vector<int>ans(m);
        while(i<m and j<m)
        {
            ans[k++]=nums[i++];
            ans[k++]=nums[j++];
        }
        return ans;
    }
};