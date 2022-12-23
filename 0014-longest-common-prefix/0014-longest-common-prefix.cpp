class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int ans=INT_MAX;
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            int j=0;
            while(j<s[i].length() and s[i][j]==s[0][j])
                j++;
            ans=min(ans,j);
        }
        return s[0].substr(0,ans);
    }
};