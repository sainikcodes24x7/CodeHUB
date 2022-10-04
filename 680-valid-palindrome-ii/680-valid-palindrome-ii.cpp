class Solution {
public:
    bool helper(string s, int left,int right)
    {
        while(left<=right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(s.length()<=2)
            return true;
        int left=0;
        int right=s.length()-1;
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                return (helper(s,left+1,right)|| helper(s,left,right-1));
            }
            left++;
            right--;
        }
        return true;
    }
};