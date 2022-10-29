class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>arr;
        int time=0,x=0,y=0;
        for(int i=0;i<plantTime.size();i++)
        {
            arr.push_back({growTime[i],plantTime[i]});
        }
        sort(arr.begin(),arr.end());
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            auto p=arr[i];
            time+=p.second;
            y=time+p.first;
            x=max(x,y);
        }
        return x;
    }
};