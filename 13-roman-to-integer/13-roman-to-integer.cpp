class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp{
            {'I',1},
            {'V',5},
            {'L',50},
            {'X',10},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]<mp[s[i+1]])
                ans-=mp[s[i]];
            else
                ans+=mp[s[i]];
        }
        return ans;
        }
    
};