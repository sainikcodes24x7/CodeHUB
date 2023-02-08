class Solution {
public:
    bool possible(int k, string s, string p, vector<int>&removable)
    {
        for(int i=0;i<k;i++)
        {
            s[removable[i]]='_';
        }
            int i=0,j=0,n=s.size(),m=p.size();
            while(i<n and j<m)
            {
                if(s[i]==p[j])
                    j++;
                i++;
            }
        
        return j==m;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n=removable.size();
        int start=0,end=n;
        int ans=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(possible(mid,s,p,removable))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};