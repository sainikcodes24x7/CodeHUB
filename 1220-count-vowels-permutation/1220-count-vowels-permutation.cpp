class Solution {
public:
    int countVowelPermutation(int n) {
        long a=1;
        long e=1;
        long i=1;
        long o=1;
        long u=1;
        
        long mod=pow(10,9)+7;
        long a2,e2,i2,o2,u2;
        for(int j=2;j<=n;j++)
        {
            a2=(e+i+u)%mod;
            e2=(a+i)%mod;
            i2=(o+e)%mod;
            o2=(i)%mod;
            u2=(o+i)%mod;
            
            a=a2;
            e=e2;
            i=i2;
            o=o2;
            u=u2;
        }
        return (a+e+i+o+u)%mod;
    }
};