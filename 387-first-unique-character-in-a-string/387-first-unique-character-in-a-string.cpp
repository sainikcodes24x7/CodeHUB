class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++)
        {
           if(mp[s[i]]==1)
               return i;
        }
        return -1;
    }
};