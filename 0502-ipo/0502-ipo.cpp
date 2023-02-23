class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>projects;
        int n=profits.size();
        for(int i=0;i<profits.size();i++)
        {
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());
        int j=0;
        priority_queue<int>pq;
        for(int i=0;i<k;i++)
        {
            while(j<n and projects[j].first<=w)
            {
                pq.push(projects[j++].second);
            }
            if(pq.empty())
                break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};