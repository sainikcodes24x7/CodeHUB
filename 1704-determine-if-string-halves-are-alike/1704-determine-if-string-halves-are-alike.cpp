class Solution {
public:
    string vow={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(vow.find(s[i])!=string::npos) cnt1++;
            if(vow.find(s[j])!=string::npos) cnt2++;
            i++;
            j--;
        }
        return cnt1==cnt2;
    }
};