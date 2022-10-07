class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int alt[n+1];
        alt[0]=0;
        for(int i=0;i<n;i++)
        {
            alt[i+1]=alt[i]+gain[i];
        }
        int maxm=0;
        for(int i=0;i<=n;i++)
        {
            maxm=max(maxm,alt[i]);
        }
        return maxm;
    }
};