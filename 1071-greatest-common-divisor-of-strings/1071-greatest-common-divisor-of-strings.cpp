class Solution {
public:
    bool helper(string s, string ans)
    {
        int n=s.size();
        int m=ans.size();
        int idx=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=ans[idx])
                return false;
            
            idx++;
            idx%=m;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int gccd=__gcd(n,m);
        string ans= str1.substr(0,gccd);
        if(helper(str1,ans) and helper(str2,ans))
            return ans;
        return "";
    }
};