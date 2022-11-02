class Solution {
public:
   int difference(string &a, string &b)
    {
        int c = 0;
        
        for(int i=0;i<8;i++)
        {
            if(a[i]!=b[i])
                ++c;
        }
        
        return c;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        
        if(start == end)
            return 0;
        
        bool present = false;
        map <string, vector <string>> adj;
        map <string, int> vis;
        map <string, int> dis;
        
        for(auto s: bank)
        {
            if(difference(s, start) == 1)
            {
                adj[s].push_back(start);
                adj[start].push_back(s);
            }
            
            if(s == end)
                present = true;
        }
        
        if(!present)
            return -1;
        
        for(auto s: bank)
        {
            if(difference(s, end) == 1)
            {
                adj[s].push_back(end);
                adj[end].push_back(s);
            }
        }
        
        for(int i=0;i<bank.size()-1;i++)
        {
            for(int j=0;j<bank.size();j++)
            {
                if(difference(bank[i], bank[j]) == 1)
                {
                    adj[bank[i]].push_back(bank[j]);
                    adj[bank[j]].push_back(bank[i]);
                }
            }
        }
        
        queue <string> q;
        q.push(start);
        vis[start] = 1;
        dis[start] = 0;
        
        while(q.size())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                string x = q.front();
                for(auto child: adj[x])
                {
                    if(vis.find(child) == vis.end())
                    {
                        q.push(child);
                        vis[child] = 1;
                        dis[child] = dis[x] + 1;
                    }
                }
                
                q.pop();
            }
        }
        
        if(dis.find(end) == dis.end())
            return -1;
        return dis[end];
    }
};