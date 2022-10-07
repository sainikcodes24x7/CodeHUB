class Solution {
public:
    int longestContinuousSubstring(string s)
    {
        int l=0;
        int r=0;
        
        int maxi=1;
        if(s.size()==1)
            return 1;
        
        if(s.size()==0)
            return 0;
        
        while(r<s.size()-1)
        {
            if(s[r]+1==s[r+1])
            {
                r++;
                maxi=max(maxi,r-l+1);
            }
            else
            {
                r++;
                l=r;
            }
        }
        return maxi;
    }
};