class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int l=0,r=0;
        int ans=0;
        
        int mx=INT_MIN;
        while(r<s.length())
        {
            mp[s[r]]++;
            mx=max(mx,mp[s[r]]);
            
            if(((r-l)+1)-mx<=k)
                ans=max(ans,(r-l)+1);
            else
            {
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};