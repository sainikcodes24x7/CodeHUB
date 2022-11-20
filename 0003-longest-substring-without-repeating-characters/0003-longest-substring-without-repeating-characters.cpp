#include<unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        unordered_set<char>st;
        int maxm=0;
        int i=0,j=0;
        //int len=0;
        while(i<s.length())
        {
            char c=s[i];
            while(st.find(c)!=st.end())
            {
                
                st.erase(s[j]);
                ++j;
                //i=i-1;
            }
            
            
                st.insert(c);
                
                maxm=max(maxm,i-j+1);
                ++i;
            
        }
        return maxm;
    }
};