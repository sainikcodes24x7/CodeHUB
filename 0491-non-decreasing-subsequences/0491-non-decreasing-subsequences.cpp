class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;
        int n=nums.size();
         for(int bitmask=0;bitmask<(1<<n);bitmask++){
             vector<int>temp;
             for(int i=0;i<n;i++){
                 if(bitmask&(1<<i))temp.push_back(nums[i]);
             }
             if(temp.size()>1){
                 if(is_sorted(temp.begin(),temp.end()))ans.insert(temp);
             }
         }
         return vector(ans.begin(),ans.end());
    }
};