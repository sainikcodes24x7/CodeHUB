class Solution {
public:
    static bool comp(vector<int>&p1, vector<int>&p2)
    {
        return p1[1]<p2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        int c=0;
        int j=0;
        sort(pairs.begin(),pairs.end(),comp);
        for(int i=1;i<n;i++)
        {
            if(pairs[i][0]>pairs[j][1])
            {
                c++;
                j=i;
            }
        }
        return c+1;
    }
};