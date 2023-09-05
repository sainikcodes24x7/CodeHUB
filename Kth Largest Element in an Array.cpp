class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
         int z=nums.size();int c=0,i=0;
         sort(nums.begin(), nums.end(), greater<int>());
           int a=nums[k-1];
            return a;
        }
    };