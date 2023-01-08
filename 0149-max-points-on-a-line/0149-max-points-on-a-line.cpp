class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res=0;
        int n=points.size();
        unordered_map<float,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                float y2=points[j][1],y1=points[i][1];
                float x2=points[j][0],x1=points[i][0];
                
                float slope=(y2-y1)/(x2-x1);
                
                if((y2-y1)<0 && (x2-x1)==0)
                    mp[abs(slope)]++;
                else
                    mp[slope]++;
            }
            
            for(auto itr:mp)
        {
            int temp=itr.second;
            res=max(res,temp);
        }
            mp.clear();
        }
        return res+1;
    }
};