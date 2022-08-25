class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,int,greater<int>>mp;
        for(int i=0;i<score.size();i++)
        {
            mp[score[i]]=i;
        }
        vector<string>ans(score.size(),"");
        int c=0;
        for(auto i:mp)
        {
            if(c==0)
                ans[i.second]="Gold Medal";
            else if(c==1)
                ans[i.second]="Silver Medal";
            else if(c==2)
                ans[i.second]="Bronze Medal";
            else
                ans[i.second]=to_string(c+1);
            c++;
        }
        return ans;
    }
};