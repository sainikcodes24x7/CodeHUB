class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int c1=0,c2=0;
        for(auto i:s)
        {
            c1+=(i-'0');
        }
        for(auto i:t)
        {
            c2+=(i-'0');
        }
        if(c1==0 and c2==0 || c1>0 and c2>0)
            return true;
        return false;
    }
};