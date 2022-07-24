class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res;
        for(int i=0;i<nums.size()-2;i++)
        {
            int s=i+1;
            int e=n-1;
            while(s<e)
            {
                int curr=nums[i]+nums[s]+nums[e];
                if(curr>target)
                    e--;
                else
                    s++;
                //if(abs(curr-target)<abs(res-target))
                  //  res=curr;
                 res=(abs(curr-target)<abs(res-target))?curr:res;
            }
        }
        return res;
        
    }
};