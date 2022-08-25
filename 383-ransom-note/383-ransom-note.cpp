class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=magazine.length();
        int m=ransomNote.length();
       unordered_map<char,int>mp;
        for(auto i:ransomNote)
        {
            mp[i]++;
        }
        for(auto i:magazine)
        {
            mp[i]--;
        }
        for(auto i:ransomNote)
        {
            if(mp[i]>0)
                return false;
        }
        return true;
    }
};