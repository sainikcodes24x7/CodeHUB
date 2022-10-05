//https://leetcode.com/contest/biweekly-contest-88/problems/bitwise-xor-of-all-pairings/
class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int xor1 =0 , xor2 =0;
        
        for (int i = 0 ; i <n ;i++)
            xor1^=nums1[i];
        for (int i = 0 ; i <m ;i++)
            xor2^=nums2[i];
        
        int ans = 0 ;
        
        if (n%2==1 && m%2==0)
            ans=xor2;
        
        else if (n%2==0 && m%2==0)
            ans=0;
        
        else if (n%2==1 && m%2==1 )
            ans = xor1^xor2 ;
        
        else if (n%2==0 && m%2==1 )
            ans = xor1 ;

        return ans;
    }
}