class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i=1;i<n;i++)
        {
            if(security[i]<=security[i-1])
                left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(security[i]<=security[i+1])
                right[i]=right[i+1]+1;
        }
        vector<int>ans;
        
        for(int day=time;day<n-time;day++)
        {
            if(left[day]>=time and right[day]>=time)
                ans.push_back(day);
        }
        return ans;
    }
};