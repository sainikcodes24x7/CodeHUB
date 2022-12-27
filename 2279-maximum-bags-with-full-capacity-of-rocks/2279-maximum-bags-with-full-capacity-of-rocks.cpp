class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans=0;
        int n=rocks.size();
        vector<int>diff;
        for(int i=0;i<n;i++)
        {
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(),diff.end());
        for(auto itr:diff)
        {
            if(itr>0 and additionalRocks>=itr)
            {
                additionalRocks-=itr;
                ans++;
            }
            else if(itr==0)
                ans++;
            else
                break;
        }
        return ans;
    }
};