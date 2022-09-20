class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(k>n)
        {
            k=k%n;
        }
        vector<int>arr(n);
        int r=n-k;
        int j=0;
        for(int i=r;i<n;i++)
        {
            arr[j++]=nums[i];
        }
        for(int i=0;i<r;i++)
        {
            arr[j++]=nums[i];
        }
        nums=arr;
    }
};