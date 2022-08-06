class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int>mapp;
        
        int n=items1.size();
        int m=items2.size();
        for(int i=0;i<n;i++)
        {
            mapp[items1[i][0]]=items1[i][1];
        }
        for(int i=0;i<m;i++)
        {
            mapp[items2[i][0]]+=items2[i][1];
        }
        vector<vector<int>>res;
        for(auto itr: mapp)
        {
           // if(itr.second>0)
            res.push_back({itr.first,itr.second});
        }
        sort(res.begin(),res.end());
        return res;
    }
};