class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans=0;
        int mod=1000000007;
        int i=1;
        while(i<=n)
        {
            ans=((ans<<(1+int(log2(i))))%mod+i)%mod;
            i++;
        }
        return ans;
    }
};