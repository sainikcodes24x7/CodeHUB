class Solution {
public:
    int maximumGap(vector<int>& nums) {
           int n = nums.size();
        int result = INT_MIN;
        sort(nums.begin(), nums.end());
        if(n < 2){
            return 0;
        }
        
        for(int i=0; i<n-1; i++){
           int diff = nums[i+1] - nums[i];
            result = max(result, diff);
        }
        return result;
    
    }
};
