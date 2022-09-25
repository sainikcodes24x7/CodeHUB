class Solution {
public:
    static bool cmp(pair<string,int>p1,pair<string,int>p2)
    {
        return p2.second<p1.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>>nameheight;
        int n=names.size();
        for(int i=0,j=0;i<n,j<n;i++,j++)
        {
            nameheight.push_back({names[i],heights[j]});
        }
        sort(nameheight.begin(),nameheight.end(),cmp);
        vector<string>ans;
        for(auto itr:nameheight)
        {
            ans.push_back(itr.first);
        }
        return ans;
    }
};