class Solution {
public:
    /*
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>>mp;
        for(int i=0;i<flights.size();i++)
        {
            int from=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];
            mp[from].push_back({price,to});
        }
        vector<int>cost(n,1e9);
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{0,src}});
        cost[src]=0;
        
        while(!q.empty())
        {
            int kval=q.front().first;
            int price=q.front().second.first;
            int currcity=q.front().second.second;
            q.pop();
            
            if(kval<=k)
            {
                for(auto nbr:mp[currcity])
                {
                    if(price+nbr.first<cost[nbr.second])
                    {
                        cost[nbr.second]=price+nbr.first;
                        q.push({kval+1,{cost[nbr.second],nbr.second}});
                    }
                }
            }
        }
        return cost[dst]==1e9?-1:cost[dst];
    }
    */
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>>mp;
        for(int i=0;i<flights.size();i++)
        {
            int from=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];
            mp[from].push_back({to,price});
        }
        vector<int>cost(n,1e9);
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{0,src}});
        cost[src]=0;
        
        while(!q.empty())
        {
            int kval=q.front().first;
            int price=q.front().second.first;
            int currcity=q.front().second.second;
            q.pop();
            
            if(kval<=k)
            {
                for(auto nbr:mp[currcity])
                {
                    if(price+nbr.second<cost[nbr.first])
                    {
                        cost[nbr.first]=price+nbr.second;
                        q.push({kval+1,{cost[nbr.first],nbr.first}});
                    }
                }
            }
        }
        return cost[dst]==1e9?-1:cost[dst];
    }
    
    
    
    
    
    
};