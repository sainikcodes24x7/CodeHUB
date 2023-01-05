class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int lastpoint=points[0][1];
        int ans=0;
        for(auto ptr:points)
        {
            if(ptr[0]>lastpoint)
            {
                ans++;
                lastpoint=ptr[1];
            }
            lastpoint=min(lastpoint,ptr[1]);
        }
        ans++;
        return ans;
    }
};