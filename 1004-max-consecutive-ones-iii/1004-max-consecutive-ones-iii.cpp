class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0;
        int i=0;
        int j=0;
        int n=nums.size();
        int countzero=0;
        while(i<n)
        {
            if(nums[i]==0)
            {
                countzero++;
            } 
            if(countzero<=k)
                res=max(res,i-j+1);
            else if(countzero>k)
            {
                if(nums[j]==0)
                    countzero--;
                j++;
            }
            i++;
        }
        return res;
    }
};