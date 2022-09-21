class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
       /* for(auto i:queries)
        {
            nums[i[1]]+=i[0];
            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]%2==0)
                {
                    sum+=nums[i];
                }
            }
            ans.push_back(sum);
        }
        return ans;
        */
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                sum+=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            int idx=queries[i][1];
            if(nums[idx]%2==0)
            {
                sum-=nums[idx];
                
            }
            nums[idx]+=queries[i][0];
            if(nums[idx]%2==0)
            {
                sum+=nums[idx];
                
            }
            ans.push_back(sum);
        }
        return ans;
    }
};