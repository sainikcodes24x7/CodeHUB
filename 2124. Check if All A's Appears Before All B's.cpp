class Solution {
public:
    bool checkString(string s) {
      //Take new string s1 and store s into it.
        string s1=s;
        int flag=0;
      //sort the s1, so that all a's comes before b's
        sort(s1.begin(),s1.end());
      //Compare s1 and s. If they match, then return true else false.
        for(int i=0;i<s.length();i++){
            if(s[i]==s1[i]) flag++;
        }
        if(flag==s.length()) return true;
        else return false;
    }
};
