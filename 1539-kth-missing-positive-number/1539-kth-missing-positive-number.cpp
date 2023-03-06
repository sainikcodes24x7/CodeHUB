class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size();
        int mid=0;
        while(low<high)
        {
            mid=(high+low)/2;
            if(arr[mid]-mid>k)
                high=mid;
            else
                low=mid+1;
        }
        return low+k;
    }
};