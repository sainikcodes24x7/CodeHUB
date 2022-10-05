class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        const int size = nums.size();
        const int max = (1 << maximumBit) - 1;

        int all = 0;
        vector<int> result(size);
        for(int i = 0; i < size; i++) {
            all ^= nums[i];
            result[size-i-1] = all ^ max;
        }

        return result;
    }

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int all = 0;
        for(auto& n : nums) {
            all ^= n;
        }
        
        int max = (1 << maximumBit) - 1; 
        vector<int> result;
        for(int i = nums.size()-1; i>=0; i--) {
            result.push_back(all ^ max);
            all ^= nums[i];
        }
        
        return result;
    }
};
