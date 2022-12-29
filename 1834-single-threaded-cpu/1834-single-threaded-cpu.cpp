class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<int>ans;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({tasks[i][0],i});
        }
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int i = 0, time = 0;
        while (i < n) {
            if (pq.empty()) time = max(time, v[i].first);
            while (i < n && v[i].first <= time) {
                pq.push({tasks[v[i].second][1], v[i].second});
                i++;
            }
            auto p = pq.top();
            pq.pop();
            time += p.first;
            ans.push_back(p.second);
        }
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;   
    }
};