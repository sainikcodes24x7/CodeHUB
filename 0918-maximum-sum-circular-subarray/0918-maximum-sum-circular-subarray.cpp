class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tot_sum=0,cur_sum1=0, cur_sum2=0,maxsubarr_sum=INT_MIN,minsubarr_sum=INT_MAX;
        for(auto i:nums)
        {
            tot_sum+=i;
            cur_sum1+=i;
            cur_sum2+=i;
            maxsubarr_sum=max(maxsubarr_sum,cur_sum1);
            if(cur_sum1<0)
                cur_sum1=0;
            minsubarr_sum=min(minsubarr_sum,cur_sum2);
            if(cur_sum2>0)
                cur_sum2=0;
        }
        if(tot_sum==minsubarr_sum)
            return maxsubarr_sum;
        else
            return max(maxsubarr_sum,tot_sum-minsubarr_sum);
    }
};