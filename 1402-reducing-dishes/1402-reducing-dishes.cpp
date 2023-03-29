class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n=s.size();
        sort(s.begin(),s.end(),greater<int>());
        vector<int>sum=s;
        
        for(int i=1;i<n;i++)
        {
            sum[i]+=sum[i-1];
        }
        int maxm=0,curmax=0;
        for(int i=0;i<n;i++)
        {
            curmax+=sum[i];
            maxm=max(maxm,curmax);
        }
        return maxm;
    }
};