class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char>map1;
        unordered_map<char,bool>map2;
        for(int i=0;i<s.length();i++)   // find two possible FALSE cases
        {
            char ch1=s[i];
            char ch2=t[i];
            if(map1.count(ch1))
            {
                if(map1[ch1]!=ch2)   //one element  in map1 mapped to two elements in map2 
                    return false;
            }
            else
            {
                if(map2[ch2])  // two elements in map1 mapped to one element in map1
                    return false;
                map1[ch1]=ch2;           // mapping is done
                map2[ch2]=true;
            }
                
        }
       return true;
        
    }
};