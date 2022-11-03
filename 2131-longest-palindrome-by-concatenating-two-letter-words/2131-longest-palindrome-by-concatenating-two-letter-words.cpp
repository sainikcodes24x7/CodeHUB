class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            reverse(str.begin(),str.end());
            if(mp[str]>0)
            {
                count+=4;
                mp[str]--;
            }
            else
            {
               mp[words[i]]++;
                
            }
        }
        for(auto i:mp)
        {
            if(i.first[0]==i.first[1] and i.second>0)
            {
                return count+2;
            }
        }
        return count;
    }
};