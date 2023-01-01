class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>chtoword;
        map<string,char>wordtoch;
        s.push_back(' ');
        string currword="";
        int curidx=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                char currch=pattern[curidx++];
                if(chtoword.count(currch))
                {
                    string alreadymapped=chtoword[currch];
                    if(alreadymapped!=currword)
                        return false;
                }
                else if(wordtoch.count(currword))
                {
                    char alreadymapped=wordtoch[currword];
                    if(alreadymapped!=currch)
                        return false;
                }
                else
                {
                    chtoword[currch]=currword;
                    wordtoch[currword]=currch;
                }
                currword="";
            }
            else
            {
                currword.push_back(s[i]);
            }
        }
        return curidx==pattern.size();
    }
};