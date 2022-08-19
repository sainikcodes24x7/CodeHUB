class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>curRow(n+1,0);
        vector<int>nextrow(n+1,0);
        
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--){
                
                //take
                int take=0;
                if(prev==-1 || nums[curr]>nums[prev])
                    take=1+nextrow[curr+1];
                
                //exclude
                int nottake=0+nextrow[prev+1];
                curRow[prev+1]=max(take,nottake);
            }
            nextrow=curRow;
        }
        return nextrow[0];
    }
};