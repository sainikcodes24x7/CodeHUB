class Solution {
public:
    void helper(vector<int>&res, int n, int k, long long val)
    {
        if(n==0)
        {
            res.push_back(val);
            return;
        }
        int lower;
        if(val==0)
            lower=1;
        else
            lower=0;
        for(int i=lower;i<10;i++)
        {
            if(val and abs(i-val%10)!=k)
                continue;
            val*=10;
            val+=i;
            helper(res,n-1,k,val);
            val/=10;
        }
        
    }
        
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        long long val=0;
        helper(res,n,k,val);
        return res;
    }
};