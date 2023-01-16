class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(),i=0;
        vector<vector<int>>res;
        while(i<n and intervals[i][1]< newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        while(i<n and intervals[i][0]<= newInterval[1])
        {
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        
        while(i<n)
        {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};