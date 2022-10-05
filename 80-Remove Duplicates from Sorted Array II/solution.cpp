class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
       int k=0;
        
        for(auto it:mp){
            if(it.second>=2){
                
            
            for(int i=0;i<2;i++){
                nums[k++]=it.first;
            }
            }
            else{
                nums[k++]=it.first;
            }
        }
        return k;
        
    }
};