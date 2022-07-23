class Solution {
public:
    bool isPalindrome(string s) {
        string a="";
        for(auto i:s)
        {
            if(iswalnum(i))
            {
                a+=tolower(i);
            }
        }
        string k=a;
        reverse(a.begin(),a.end());
        return k==a;
    }
};