class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        int i=0,j=0;
        
        int counter=t.size();
        int minstart=0;
        int minlength=INT_MAX;
        
        while(j<s.size())
        {
            if(mp[s[j]]>0)
                counter--;
            mp[s[j]]--;
            j++;
            
            while(counter==0)
            {
                if(j-i<minlength)
                {
                    minstart=i;
                    minlength=j-i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                    counter++;
                i++;
            }
        }
        if(minlength!=INT_MAX)
        {
            return s.substr(minstart,minlength);
        }
        return "";
    }
};