class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        for(int i=0;i<n;i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int m=nums1.size();
        if(m%2!=0)
            return double(nums1[nums1.size()/2]);
        else
        {
            double a=nums1[(nums1.size()/2)-1];
            double b=nums1[nums1.size()/2];
            return (a+b)/2;
        }
    }
};