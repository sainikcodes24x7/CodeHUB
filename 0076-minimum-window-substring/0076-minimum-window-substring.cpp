class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        int i=0,j=0;
        int minstart=0;
        int minlength=INT_MAX;
        int c=t.size();
        while(j<s.size())
        {
            if(mp[s[j]]>0)
                c--;
            mp[s[j]]--;
            j++;
            while(c==0)
            {
                if(j-i<minlength)
                {
                    minstart=i;
                    minlength=j-i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                    c++;
                i++;
            }
        }
        cout<<minlength;
        if(minlength!=INT_MAX)
            return s.substr(minstart,minlength);
        return "";
    }
};