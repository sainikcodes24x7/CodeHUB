class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        queue<int>q;
        vector<bool>vis(n,false);
        int steps=0;
        q.push(0);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int curridx=q.front();
                q.pop();
                if(curridx==n-1)
                    return steps;
                if(curridx+1<n and !vis[curridx+1])
                {
                    vis[curridx+1]=true;
                    q.push(curridx+1);
                }
                if(curridx-1>=0 and !vis[curridx-1])
                {
                    vis[curridx-1]=true;
                    q.push(curridx-1);
                }
                for(auto nbr:mp[arr[curridx]])
                {
                    if(!vis[nbr])
                    {
                        vis[nbr]=true;
                        q.push(nbr);
                    }
                }
                mp[arr[curridx]].clear();
            }
            steps++;
        }
        return -1;
    }
};