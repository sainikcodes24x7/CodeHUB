class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            //int rem_sum=abs(k-sum);
            int rem_sum=sum-k;
            count+=mp[rem_sum];
            mp[sum]++;
        }
        return count;
    }
};