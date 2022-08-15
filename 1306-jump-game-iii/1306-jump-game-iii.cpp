class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int,bool>vis;
        queue<int>q;
        vis[start]=true;
        q.push(start);
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            
            //if you can reach to any index with value 0 return true
            if(arr[top]==0)
            {
                return true;
            }
            if(top+arr[top]<arr.size() and !vis[top+arr[top]])
            {
                q.push(top+arr[top]);
                vis[top+arr[top]]=true;
            }
            if(top-arr[top]>=0 and !vis[top-arr[top]])
            {
                q.push(top-arr[top]);
                vis[top-arr[top]]=true;
            }
        }
        return false;
    }
};