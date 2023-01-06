class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int idx=nums.size()-k;
            return nums[idx];
    }
};