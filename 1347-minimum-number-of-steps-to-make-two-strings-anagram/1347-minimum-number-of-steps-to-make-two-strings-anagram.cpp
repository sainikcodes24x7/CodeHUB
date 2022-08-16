class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>mp(26,0),mp1(26,0);
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]-'a']++;
        }
         for(int i=0;i<t.length();i++)
        {
            mp1[t[i]-'a']++;
             //res+=abs(mp[t[i]]);
        }
        for(int i=0;i<26;i++)
        {
            res+=abs(mp1[i]-mp[i]);
        }
        //same words are counted twice
        return res/2;
    }
};