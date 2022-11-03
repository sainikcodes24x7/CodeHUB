class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int gl=g.size()-1;
        int sl=s.size()-1;
        int cookies=0;
        while(gl>=0 and sl>=0)
        {
            if(s[sl]>=g[gl])
            {
                sl--;
                gl--;
                cookies++;
            }
            else
            {
                gl--;
            }
        }
        return cookies;
    }
};