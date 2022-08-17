class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        for(auto num:arr)
        {
            mp[num]++;
        }
        for(auto n:mp)
        {
            pq.push({n.second,n.first});
        }
        
        while(k and pq.size()!=0)
        {
            pair<int,int>tp=pq.top();
            pq.pop();
            int res=min(tp.first,k);
            tp.first-=res;
            k-=res;
            if(tp.first)
                pq.push(tp);
        }
        return pq.size();
    }
    
};