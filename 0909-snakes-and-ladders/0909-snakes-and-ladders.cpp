class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m=board.size();
        vector<int>moves={1,2,3,4,5,6};
        queue<int>q;
        q.push(0);
        
        vector<int>arr;
        int diceroll=0;
        
        int k=0;
        for(int i=m-1;i>=0;i--){ 
            if(k%2!=0) reverse(board[i].begin(),board[i].end()); 
            arr.insert(arr.end(),board[i].begin(),board[i].end()); 
            k++;
        } 
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        /*for(int i=0;i<2*arr.size();i+=2)
        {
            mp[arr[i]]=arr[i];
        }
        */
        
        vector<int>vis(arr.size(),0);
        vis[0]=1;
        while(!q.empty())
        {
            diceroll++;
            int s=q.size();
            while(s--)
            {
                int cur=q.front();
                q.pop();
                for(auto move:moves){
                    int nxt=cur+move;
                    if(arr[nxt]>-1) 
                        nxt=arr[nxt]-1;
                    // updating for snake or ladder
                    if(nxt>=arr.size()-1) 
                        return diceroll; // reached goal
                    if(!vis[nxt]){
                        vis[nxt]=1;
                        q.push(nxt);
                    }
                }
            }
        }
        
       return -1;
    }
};