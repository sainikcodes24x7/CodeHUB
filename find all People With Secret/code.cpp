 #define pp pair<int,int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        unordered_map<int,vector<pair<int,int>>> check(n);
        vector<bool> visited(n,false);
        for(auto x:meetings){
            check[x[0]].push_back({x[1],x[2]});
            check[x[1]].push_back({x[0],x[2]});
    }
     
        priority_queue<pp,vector<pp>,greater<pp>> mp;
        mp.push({0,firstPerson});
        mp.push({0,0});
        while(mp.size()>0){
            
            auto [time,t]=mp.top();
            mp.pop();
            if(visited[t])
                continue;
            visited[t]=true;
            for(auto [x,tme]:check[t])
                if(tme>=time)
                    mp.push({tme,x});
        }
        
        vector<int> ans;
        ans.push_back(0);
     for(int i=1;i<n;i++)
         if(visited[i])
             ans.push_back(i);
        
        return ans;
    }
