class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int hash[27]={0};
        for(int i=0;i<s.length();i++){
            hash[s[i]-97]+=1;
        }
        for(int i=0;i<t.length();i++){
            hash[t[i]-97]-=1;
           
        }
        for(int i=0;i<26;i++){
            if(hash[i]<0){
                return false;
            }
        }
       return true;

    }
};