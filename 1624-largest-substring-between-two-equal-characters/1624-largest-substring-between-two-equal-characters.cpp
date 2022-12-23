class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        int maxlength=-1;
        for(int i=0;i<n-1;i++)
        {
            
            if(mp[s[i]]!=-1)
            {
                for(int j=n-1;j>i;j--)
                {
                    if(s[i]==s[j])
                    {
                        maxlength=max(maxlength,j-i-1);
                        break;
                    }
                }
            }
        }
        return maxlength;
    }
};