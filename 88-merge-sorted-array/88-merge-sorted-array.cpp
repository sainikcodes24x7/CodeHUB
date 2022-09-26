class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //int sz=max(n,m);
        //vector<int>ans(sz);
        int ans[400];
        int i=0,j=0;
        int k=0;
        while(i<m and j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                ans[k++]=nums1[i++];
            }
            else if(nums1[i]>nums2[j])
            {
                ans[k++]=nums2[j++];
            }
           
        }
        while(i<m)
        {
            ans[k++]=nums1[i++];
        }
        while(j<n)
        {
            ans[k++]=nums2[j++];
        }
        //int s=ans.size();
        for(int i=0;i<n+m;i++)
        {
            nums1[i]=ans[i];
        }
    }
};