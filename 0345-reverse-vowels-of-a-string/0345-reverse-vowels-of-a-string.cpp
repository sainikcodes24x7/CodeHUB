class Solution {
public:
    bool checkvowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(checkvowel(s[i]))
            {
                while(i<j)
                {
                    if(checkvowel(s[j]))
                    {
                        swap(s[i],s[j]);
                        j--;
                        break;
                    }
                    j--;
                }
            }
            i++;
        }
        return s;
    }
};