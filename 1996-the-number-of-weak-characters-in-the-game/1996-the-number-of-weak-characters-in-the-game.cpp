class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if(a[0]!=b[0])
            return a[0]>b[0];
        else
            return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(),prop.end(),cmp);
        int maxtillnow=INT_MIN;
        int cnt=0;
        for(auto i:prop)
        {
            if(maxtillnow>i[1])
            {
                cnt++;
            }
            else
            {
                maxtillnow=i[1];
            }
        }
        return cnt;
    }
};