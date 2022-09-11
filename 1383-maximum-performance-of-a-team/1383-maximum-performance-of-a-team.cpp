class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>perf;
        for(int i=0;i<n;i++)
        {
            perf.push_back({efficiency[i],speed[i]});
        }
        
        //sorting has been done in descending order
        sort(rbegin(perf),rend(perf));
        
        //priority queue to get the smallest sum ie least efficient person
        priority_queue<int,vector<int>,greater<int>>pq;
        long runningsum=0;
        long res=0;
        
        for(auto itr:perf)
        {
            runningsum+=itr.second;
            //push this in priority queue
            pq.push(itr.second);
            
            //if employee size exceed the limit remove the inefficient/slowest person
            if(pq.size()>k)
            {
                runningsum-=pq.top();
                pq.pop();
            }
            
            res=max(res,(itr.first*runningsum));
        }
        return res%(int)(1e9+7);
    }
};