class Solution {
public:
   int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        int i=0;
        for(int k=m-1;k<n;k++)  // first window length is word-srched length
        {
            if(haystack.substr(i,k-i+1)==needle) // if word found
                return i; // return start index
                i++;
        }
        return -1;
    }
};