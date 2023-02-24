class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int lastone=intervals[0][1];
        int c=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<lastone)
                c++;
            else
                lastone=intervals[i][1];
        }
        return c;
    }
};