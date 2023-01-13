class Solution {
public:
    int helper(vector<vector<int>>&v, string &s, string &t, int i, int j)
    {
        if(i<0 ||j<0)
            return 0;
        if(v[i][j]!=-1)
            return v[i][j];
        if(s[i]==t[j])
            return v[i][j]=1+helper(v,s,t,i-1,j-1);
        return v[i][j]=max(helper(v,s,t,i-1,j),helper(v,s,t,i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.length()-1;
        vector<vector<int>>v(n+2,vector<int>(n+2,-1));
        return helper(v,s,t,n,n);
    }
};