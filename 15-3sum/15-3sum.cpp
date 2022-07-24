class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            int start=i+1;
            int end=n-1;
            int ncurr=-curr;
            while(start<end)
            {
                if(nums[start]+nums[end]==ncurr){
                ans.push_back({nums[i],nums[start],nums[end]});
                
                while(start<end and (nums[start+1]==nums[start]))
                    start++;
                while(start<end and (nums[end-1]==nums[end]))
                    end--;
                
                start++;
                end--;
                }
                else if(nums[start]+nums[end]>ncurr)
                {
                    end--;
                }
                else{
                    start++;
                }
                
            }
            while(i+1<n and nums[i+1]==nums[i])
                i++;
            
        }
        return ans;
    }
};