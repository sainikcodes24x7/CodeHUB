class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)
            return false;
        int p=x,rev=0;
        while(p>0)
        {
            rev=rev*10 + p%10;
            p/=10;
        }
        return x==rev;
    }
}