class Solution {
public:
    int merge(int start, int mid, int end, vector<int>& nums)
    {
       int j=mid+1;
       int count=0;
       for(int i=start;i<=mid;i++)
       {
          while(j<=end and nums[i]>(long long)2*nums[j])
          {
              j++;
          }
           count+=(j-(mid+1));
       }
        int n=nums.size();
        vector<int>temp;
        int k=0;
        int i=start;j=mid+1;
        while(i<=mid and j<=end)
        {
            if(nums[i]>nums[j])
            {
                temp.push_back(nums[j++]);
            }
            else{
                temp.push_back(nums[i++]);
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i++]);
        }
        while(j<=end)
        {
            temp.push_back(nums[j++]);
        }
        for(i=start;i<=end;i++)
        {
            nums[i]=temp[i-start];
        }
        return count;
    
    }
    int mergesort(int s, int e, vector<int>& nums)
    {
        if(nums.size()==0)
            return 0;
        if(s<e)
        {
            int mid=(s+e)/2;
            int ans=0;
            ans+=mergesort(s,mid,nums);
            ans+=mergesort(mid+1,e,nums);
            ans+=merge(s,mid,e,nums);
            return ans;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(0,n-1,nums);
    }
};